# Erik's notes

## 24-02-07 Meeting
 - [Multivariable Chain Rule](https://www.khanacademy.org/math/multivariable-calculus/multivariable-derivatives/differentiating-vector-valued-functions/a/multivariable-chain-rule-simple-version)
 - Newtonian Fluids are fluids where stress is proportional to strain in all axis.
 - Isotropic: Same in all directions.
 - Toothpaste is an example of a non-Newtonian fluid.
 - Eulerian Perspective: Consider changes in fluid from a fixed point in space.
 - Lagrangian Perspective: Consider changes in fluid from a a moving particle.
 - Advection: The transfer of matter by flow.
 - Material Derivative: The rate of change of a vector with respect to both time and its own components. Useful when you want to define how a fluid moves with respect to time and the overall gradient of fluid.
 $$\frac{Du}{Dt} = (\frac{d}{dt}+u\cdot \nabla) u$$
 - Navier Stokes Equation:
 $$\frac{Du}{Dt} = -\frac{1}{\rho}\nabla p + v \nabla^2u + F$$
 $$\nabla u = 0$$
 - $\frac{Du}{Dt}$: The material derivative of the movement of the fluid.
 - $-\frac{1}{\rho}\nabla p$: The negative pressure gradient.
 - $v\nabla^2u$: Something to do with diffusion and shear forces. *Maybe I copied it down wrong?*
 - $F$: Any external forces such as Weight. 

## 24-02-14
 'Derivation' of Material Derivative:
 $$\text{Let: }f(t) = f\left(x(t), y(t),z(t),t \right)$$ 
 $$\text{By chain rule: } \frac{Df}{Dt} = \frac{\delta f}{\delta t} + \frac{\delta f}{\delta x}\frac{\delta x}{\delta t} + \frac{\delta f}{\delta y}\frac{\delta y}{\delta t} + \frac{\delta f}{\delta z}\frac{\delta z}{\delta t}$$
 $$\frac{Df}{Dt} = \frac{\delta f}{\delta t} + \frac{\delta f}{\delta x}\dot x + \frac{\delta f}{\delta y}\dot y + \frac{\delta f}{\delta z}\dot z$$
 $$\frac{Df}{Dt} = \frac{\delta f}{\delta t} + \begin{pmatrix}\dot x \\ \dot y \\ \dot z \end{pmatrix}\cdot \begin{pmatrix}\frac{\delta x}{\delta t} \\ \frac{\delta y}{\delta t} \\ \frac{\delta z}{\delta t}\end{pmatrix}$$
 $$\frac{Df}{Dt} = \frac{\delta f}{\delta t} + u\cdot \nabla f $$
 $$\text{Bring $f$ out: } \frac{Df}{Dt} = \left(\frac{\delta}{\delta t} + u\cdot \nabla \right)f$$
 With the Navier-Stokes equation, it happens that $f$ is $u$ too.

 ## 24-02-20
  - We can assume incompressibility in air because this only matters at the speed of sound. The atmosphere moves at slower speeds.
  >In general, though, fluids are not compressible. For example, sound waves are exactly waves of compression in air, and cannot exist if air is incompressible. So we can alternatively state the assumption of incompressibility as “sound travels at infinite speed”. Hence, compressibility matters mostly when we are travelling near the speed of sound. If we are moving in low speeds, we can just pretend the fluid is indeed incompressible.
  > --<cite> Dexter, Dexter's Notes (2016).