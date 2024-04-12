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
 $$\textbf{(Def. of Newtonian Fluid) } \tau = \mu \frac{d u}{dy}$$
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

## 24-03-18
 - Prandtl number is the ratio of kinematic viscosity (momentum diffusivity) to thermal diffusivity.
 - It represents how a fluid transfers heat. Low values mean that conduction 'dominates', whilst higher mean convection is a larger contributor to heat transfer.
 - It is dimensionless.
 - $$Pr = \frac{\nu}{\alpha} = \frac{\mu / \rho}{k / (C_p / \rho)} = \frac{\mu \cdot c_p}{k}$$
 - Remember $\nu$ is the kinematic viscosity, a measure of resistance to shear forces ($m^2 s^{-1}$).
 - $k$ is thermal conductivity, in $Wm^{-1}K^{-1}$.
 - $c_p$ is specific heat $Jkg^{-1}K^{-1}$.
 - $\alpha$ is the thermal diffusivity ($m^2 s^{-1}$), representing how fast heat diffuses through a material.
 - $$\alpha = \frac{\text{Heat conducted}}{\text{Heat stored}} = \frac{k}{\rho \cdot c_p}$$
 - Rayleigh number: product of Grashof Number and Prantdl number. Describes how turbulent (high numbers) or laminar (low numbers) the flow is.
 - Grashof number is the ratio of buoyant forces to viscous forces.
 - Natural convection is a synonym for buoyancy-driven flow.
 - Air becomes turbulent at around $Ra > 10^9$.
 > https://www.thermal-engineering.org/what-is-prandtl-number-definition/  
 > https://www.thermal-engineering.org/what-is-thermal-diffusivity-definition/  
 > https://www.thermal-engineering.org/what-is-rayleigh-number-definition/  
 > Accessed: 18/03/23   
 > https://www.thermal-engineering.org/what-is-grashof-number-definition/  
 > Accessed: 19/03/23  

## 24-04-04  
#### Javascript Lorenz Plotter Analysis
 - Created plotter for Lorenz in Blender (for pretty renders) and JavaScript (for actual analysis).
 - Typical shape is "the butterfly" with two spirals and the particle oscillates between the two.
 - Interesting that as long as initial x and y are non-zero and, the trajectory will tend to the similar butterfly shape at a similar position.
 - The greater $\rho$ is compared to $\sigma$, the more the particle oscillates between the two "wings".
 - It may also be that when $\rho$ is roughly greater than $\sigma \times \beta$, two wings emerge, else the particle converges to a point in one spiral.
 - Large values generally increase the scale of the butterfly.
 - "Small values yield unsatisfying results".
 - Initial $x, y=0$ gives a straight line to origin, which makes sense since there's no rate of convection or vertical temperature variation.

#### Reading the Paper
 - 2 main sources of error: lack of information regarding initial atmospheric conditions and loss of accuracy in calculation.
 > "Ensemble prediction provided a way to overcome one of the problems highlighted by Simmons et al. (1995), since it can be used to estimate the forecast skill of a deterministic forecast, or, in other words, to forecast the forecast skill."  
 > --<cite> Roberto Buizza (2002) "Chaos and Weather Prediction" ECMWF

## 24-04-10
#### Lorenz Plotter in C++
 - C++ provided the performance to plot multiple attractors.
 ![R1.png](./Code/Lorenz-CPP/Renders/R1.png)
 - Simulation shows that the final value can take anything on the edges, with a very small variance in starting position.
 - This shows that the weather is unpredictable, since each red dot is a possible state.

## 24-04-12
#### Some Vocabulary from Youtube
- Chaotic Deterministic:
    - Not random: There is one solution for every starting condition
    - Aperiodic behaviour over time
    - Sensitive to starting conditions
- Dynamic System
    - Involves variables that change over time according to autonomous differential equations.
    - Autonomous Differential Equation: A DE that does not depend on the independent variable. There is not "t" in the equation, other than "dt".
- Attractors: The set of points in phase space that attracts all the trajectories in the area surrounding it.
    - Basin of attraction: The points that are attracted to the attractor.
    - Fixed Point Attractor: The attractor does not move, and points that are attracted to it do not escape.
    - Limit Cycle Attractor
- Lorenz Attractor:
    - Strange Chaotic Attractor
    - Fractal structure: No point is visited twice, no two trajectories intersect.
    - Dimension ~ 2.06
- Lyapunov Exponent:
    - A factor in measuring distance between trajectories. Used to measure and predict error.
    - $d_t = d_0 e^{\lambda t}$
    - Found experimentally
    - ~0.9 for Lorenz Attractor.
    - Rearrange for $t$ to find the time given a certain error. Known as the "predictability horizon"; when error becomes to large to predict meaningfully. 
    - $t = \frac{1}{\lambda} \ln{\frac{\alpha}{d_0}}\; \alpha =$ maximum error.
    - Video gives example to find how much more accurate an initial error of $1\mu m$ is vs $1m$ for $1km$ error.
    $$\frac{\frac{1}{\lambda} \ln{\left( \frac{1000}{10^{-6}}\right)}}{\frac{1}{\lambda}\ln{\left( \frac{1000}{1}\right)}} = \frac{\ln{10^9}}{\ln{10^3}} = \frac{9}{3} = 3$$
    - Very difficult to forecast more than a week ahead.

> Gonkee (2021) *Chaos Theory: The language of (in)stability* Youtube url: https://www.youtube.com/watch?v=uzJXeluCKMs

#### Ensemble Weather Prediction:
 - Summary: Consider the vectors along which errors are most likely to occur, and sample these directions with a higher resolution.
 - Initial observations can be measured in more detail by sending planes or focussing satellites.
 - After recording data, the simulation has to be adjusted to meet these new observations (assimilation). In this time, more perturbations can occur.
 - Ensemble weather prediction tries to consider these perturbations whilst during assimilation.