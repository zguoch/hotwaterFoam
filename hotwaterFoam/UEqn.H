    // Solve the momentum equation

    fvVectorMatrix UEqn
    (
        fvm::ddt(U) + fvm::div(phi, U) - fvm::laplacian(mu_f/rho0_f, U)
    );

    UEqn.relax();

    if (pimple.momentumPredictor())
    {
        solve
        (
            UEqn
         ==
            fvc::reconstruct
            (
                (
                  - ghf*fvc::snGrad(rhok)
                  - fvc::snGrad(p_rgh)
                )*mesh.magSf()
            )
        );
    }