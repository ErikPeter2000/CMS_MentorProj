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
 $$\frac{Du}{Dt} = -\frac{1}{\rho}\nabla p + \nu \nabla^2u + F$$
 $$\nabla \cdot u = 0$$
 - $\frac{Du}{Dt}$: The material derivative of the movement of the fluid.
 - $-\frac{1}{\rho}\nabla p$: The negative pressure gradient.
 - $v\nabla^2u$: Something to do with diffusion and shear forces. *~~Maybe I copied it down wrong?~~ shown on 04-03.*
 - $F$: Any external forces such as Weight. 

## 24-02-14
 'Derivation' of Material Derivative:
 $$\text{Let: }f(x,y,z,t) = f\left(x(t), y(t),z(t),t \right)$$ 
 $$\text{By chain rule, we define: } \frac{Df}{Dt} = \frac{\partial f}{\partial t} + \frac{\partial f}{\partial x}\frac{\partial x}{\partial t} + \frac{\partial f}{\partial y}\frac{\partial y}{\partial t} + \frac{\partial f}{\partial z}\frac{\partial z}{\partial t}$$
 $$\frac{Df}{Dt} = \frac{\partial f}{\partial t} + \frac{\partial f}{\partial x}\dot x + \frac{\partial f}{\partial y}\dot y + \frac{\partial f}{\partial z}\dot z$$
 $$\frac{Df}{Dt} = \frac{\partial f}{\partial t} + \begin{pmatrix}\dot x \\ \dot y \\ \dot z \end{pmatrix}\cdot \begin{pmatrix}\frac{\partial x}{\partial t} \\ \frac{\partial y}{\partial t} \\ \frac{\partial z}{\partial t}\end{pmatrix}$$
 $$\frac{Df}{Dt} = \frac{\partial f}{\partial t} + u\cdot \nabla f $$
 $$\text{Bring $f$ out: } \frac{Df}{Dt} = \left(\frac{\partial}{\partial t} + u\cdot \nabla \right)f$$
 With the Navier-Stokes equations, it happens that $f$ is $u$.

## 24-02-20
  - We can assume incompressibility in air because this only matters at the speed of sound. The atmosphere moves at slower speeds.
  >In general, though, fluids are not compressible. For example, sound waves are exactly waves of compression in air, and cannot exist if air is incompressible. So we can alternatively state the assumption of incompressibility as “sound travels at infinite speed”. Hence, compressibility matters mostly when we are travelling near the speed of sound. If we are moving in low speeds, we can just pretend the fluid is indeed incompressible.
  > --<cite> Dexter, Dexter's Notes (2016).

## 24-03-04
 - Viscosity is a proportion of stress to rate of strain in a fluid.
 - $$ \textbf{(Shear Strain) } \Delta \gamma = \frac{\Delta u \Delta t }{\Delta y}$$
 $$\frac{\Delta \gamma}{ \Delta t} = \frac{\Delta u }{\Delta y} $$
 $$\dot{\gamma} = \frac{d u}{dy}$$
 $$\textbf{(Def. of Netwonian Fluid) } \tau = \mu \frac{d u}{dy}$$
 $$\tau = \mu\dot\gamma$$
 - The above equation makes sense when compared to solids since Newtonian fluids deform completely. For solids $\tau = \sigma \gamma$.
 - We can then then do dimensional analysis to show that the unit for viscosity is Pascal-seconds. Stress has no units and rate is $\text{s}^{-1}.$
 - Kinematic viscosity is dynamic viscosity per density, or $\nu = \frac{\mu}{\rho}$. This is seen in the form of the Navier-Stokes equations Charles gave us.
 - Dexter's Notes part 1 shows that the equations for steady, laminar flow in one direction for a 2D plane to be as below. This is achieved by imagining the flow as layers or boxes with dimensions tending to 0, and equating the stresses for the x and y components:
 $$\mu\frac{\partial^2 u}{\partial y^2} -\frac{\partial u}{\partial x}= 0$$
 $$\frac{\partial p}{\partial y} = 0$$
 - The $\nu \nabla^2 u$ term in the Navier-Stokes equation models turbulence, and can be ignored for fluids with high viscosity.
 - Rayleigh Number (Ra): How turbulent the flow is. Higher is more turbulent; Lower is laminar. *I will look into derivation*.

## 24-03-07 Meeting
 - $Q$ is the rate of heat transfer into the system. $Q$ varies $T$, which changes $\rho$. This is expressed mostly in $c_p \frac{DT}{dt} = Q$. Note that $c_p$ is just heat capacity **not specific** heat capacity.
 - Buoyancy can be considered to be an acceleration given by $-g\frac{\rho - \rho_0}{\rho_0}$ where $\rho_0$ is a relative density.
 - Convection can be unstable with variations in density, as a hot particle rising into cooler air will keep rising chaotically.
 - $u \cdot \nabla u$ is the main difficulty when solving the Navier-Stokes equation because it's non-linear. $\nu \nabla^2 u$ is not (nearly) as difficult.

## 24-03-24
 - Prandtl number is the ratio of kinematic viscosity (momentum diffusivity) to thermal diffusivity.
 - It represents how a fluid transfers heat. Low values mean that conduction 'dominates', whilst higher mean convection is a larger contributor to heat transfer.
 - It is dimensionless.
 - $$Pr = \frac{\nu}{\alpha} = \frac{\mu / \rho}{k / (C_p / \rho)} = \frac{\mu \cdot c_p}{k}$$
 - Remember $\nu$ is the kinematic viscosity, a measure of resistance to shear forces ($m^2 s^{-1}$).
 - $k$ is thermal conductivity, in $Wm^{-1}K^{-1}$.
 - $c_p$ is specific heat $Jkg^{-1}K^{-1}$.
 - $\alpha$ is the thermal diffusivity ($m^2 s^{-1}$), representing how fast heat diffuses through a material.
 - $$\alpha = \frac{\text{Heat conducted}}{\text{Heat stored}} = \frac{k}{\rho \cdot c_p}$$

 > https://www.thermal-engineering.org/what-is-prandtl-number-definition/  
 > https://www.thermal-engineering.org/what-is-thermal-diffusivity-definition/  
 > https://www.thermal-engineering.org/what-is-rayleigh-number-definition/  
 > Accessed: 18/03/23  