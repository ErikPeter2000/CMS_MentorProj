import bpy
import math
import numpy as np
import time

sigma = 10
rho = 28
beta = 8/3
dt = 0.01
initial = (0.1,0.0,0.0)

def generate_lorenz_trajectory(num_points, x=initial[0], y=initial[1], z=initial[2]):
    print("Caclulating Trajectory")
    points = np.zeros((num_points, 3))
    inc = num_points//10
    for i in range(num_points):
        dx = sigma * (y - x) * dt
        dy = (x * (rho - z) - y) * dt
        dz = (x * y - beta * z) * dt
        x, y, z = x + dx, y + dy, z + dz
        points[i] = [x, y, z]
        if i % inc == 0:
            print(f"{i}/{num_points}")
    print(f"{num_points}/{num_points}")
    return points

def create_bezier_curve(points):
    print("Creating bezier")
    curve_data = bpy.data.curves.new('LorenzCurve', 'CURVE')
    curve_data.dimensions = '3D'

    num_points = len(points)
    spline = curve_data.splines.new('BEZIER')
    spline.bezier_points.add(num_points - 1)
    bezier_points = spline.bezier_points
    
    flat_points = points.flatten()
    bezier_points.foreach_set("co", flat_points)

    obj = bpy.data.objects.new('LorenzCurveObj', curve_data)
    bpy.context.collection.objects.link(obj)
    bpy.context.view_layer.objects.active = obj
    bpy.ops.object.mode_set(mode='EDIT')
    bpy.ops.curve.select_all(action='SELECT')
    bpy.ops.curve.handle_type_set(type='AUTOMATIC')
    bpy.ops.object.mode_set(mode='OBJECT')
    return obj

def delete_all_curve():
    bpy.ops.object.select_all(action='DESELECT')
    bpy.ops.object.select_by_type(type='CURVE')
    bpy.ops.object.delete()
              
def setup_geo_nodes(obj, graph_name):
    modifier = obj.modifiers.new(name="GeometryNodes", type='NODES')
    node_group = bpy.data.node_groups.get(graph_name)
    modifier.node_group = node_group

def attach_material(obj, mat_name):
    mat = bpy.data.materials.get(mat_name)
    obj.data.materials.append(mat)

def add_text_to_camera(text):    
    text_object = bpy.data.objects.new("Text", bpy.data.curves.new("TextCurve", 'FONT'))
    bpy.context.collection.objects.link(text_object)
    
    text_object.data.body = text
    text_object.data.size = 0.02
    text_object.data.align_x = 'LEFT'
    text_object.data.align_y = 'BOTTOM'
    
    camera = bpy.context.scene.camera
    if camera:
        text_object.parent = camera
        text_object.parent_type = 'OBJECT'
        text_object.location = (-0.7,-0.52,-2)
    return text_object
        

start_time = time.time()
num_points = 50000
graph_name = "LorenzCurveGeoNodes"
delete_all_curve()
trajectory_points = generate_lorenz_trajectory(num_points)
obj = create_bezier_curve(trajectory_points)

print("Setting up geo-nodes and materials")
setup_geo_nodes(obj, graph_name)
attach_material(obj, "LorenzCurveMat")
text_obj = add_text_to_camera(f"Sigma: {sigma:d} | Rho: {rho:d} | Beta: {beta:.2f} | Delta: {dt} | Start: ({initial[0]}, {initial[1]}, {initial[2]}) | Steps: {num_points}")
attach_material(text_obj, "WhiteTextMat")
print(f"Done! {time.time() - start_time:.2f}s")