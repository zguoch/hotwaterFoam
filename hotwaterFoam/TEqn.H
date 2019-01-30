{
    fvScalarMatrix TEqn
    (
        fvm::ddt(T)
      + fvm::div(phi, T)
      - fvm::laplacian(DT/cp_f/rho0_f, T)
    );

    TEqn.relax();

    TEqn.solve();

    rhok = 1.0 - alpha_f*(T - T0);
    // 真是密度
    rho=rhok*rho0_f;
}
