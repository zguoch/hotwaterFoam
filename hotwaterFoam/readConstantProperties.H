
Info<< "Reading constantProperties\n" << endl;

IOdictionary constantProperties
(
    IOobject
    (
        "constantProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

//2. Boussinesq近似的基准温度，一般设置为T0=273.15K=0C
dimensionedScalar T0(
    constantProperties.lookup("T0"));

//3. 流体在T0温度条件下的密度
dimensionedScalar rho0_f(
    constantProperties.lookup("rho0_f"));

Info<< "Reading diffusivity DT\n" << endl;
dimensionedScalar DT
(
    constantProperties.lookup("DT")
);

dimensionedScalar cp_f
(
    constantProperties.lookup("cp_f")
);

dimensionedScalar mu_f
(
    constantProperties.lookup("mu_f")
);

//7. 流体的热膨胀系数
dimensionedScalar alpha_f(
    constantProperties.lookup("alpha_f"));

//8. 流体的压缩系数
dimensionedScalar beta_f(
    constantProperties.lookup("beta_f"));