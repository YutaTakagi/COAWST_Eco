!
!svn $Id: fennel_mod.h 585 2012-01-03 18:44:28Z arango $
!================================================== Hernan G. Arango ===
!  Copyright (c) 2002-2012 The ROMS/TOMS Group                         !
!    Licensed under a MIT/X style license                              !
!    See License_ROMS.txt                                              !
!=======================================================================
!================================================== Takashi Nakamura ===
!                                                                      !
!  Parameters for Coral reef ecosystem model:                          !                                                                   !
!                                                                      !
!=======================================================================
!
      USE mod_param
      USE mod_ocean
      USE mod_reef_ecosys_param
      USE mod_sedecosys
      USE mod_coral
      USE mod_seagrass
      USE mod_macroalgae
!
      implicit none
!
!  Set biological tracer identification indices.
!
      integer :: idCrl1                 ! Coral coverage
      integer :: idCrl2                 ! Coral2 coverage
      integer :: idSgrs                 ! Seagrass coverage
      integer :: idAlga                 ! Algal coverage
      integer :: idSand                 ! Sand coverage

      integer, allocatable :: idbio(:)  ! Biological tracers
      integer :: iDO                    ! Dissolved oxygen concentration
      integer :: iTA                    ! Total alkalinity
      integer :: iDIC(N_Csp)            ! Total inorganic carbon
      integer :: iNO3(N_Nsp)            ! NO3 concentration
      integer :: iNH4(N_Nsp)            ! NH4 concentration
      integer :: iPO4(N_Psp)            ! PO4 concentration
      integer :: iDOC(N_Csp,Ndom)       ! Dissolved organic C-concentration
      integer :: iPOC(N_Csp,Npom)       ! Particulate organic C-concentration
      integer :: iDON(N_Nsp,Ndom)       ! Dissolved organic N-concentration
      integer :: iPON(N_Nsp,Npom)       ! Particulate organic N-concentration
      integer :: iDOP(N_Psp,Ndom)       ! Dissolved organic P-concentration
      integer :: iPOP(N_Psp,Npom)       ! Particulate organic P-concentration
      integer :: iPhyC(N_Csp,Nphy)      ! Phytoplankton1 density
      integer :: iZooC(N_Csp,Nzoo)      ! Zooplankton density
      integer :: iPhyN(N_Nsp,Nphy)      ! Phytoplankton1 density
      integer :: iZooN(N_Nsp,Nzoo)      ! Zooplankton density
      integer :: iPhyP(N_Psp,Nphy)      ! Phytoplankton1 density
      integer :: iZooP(N_Psp,Nzoo)      ! Zooplankton density
      integer :: iPIC(N_Csp,Npim)        ! Particulate inorganic C-concentration
#if defined COT_STARFISH
      integer :: iCOTe                  ! Eggs of crown-of-thorns starfish
      integer :: iCOTl                  ! Larvae of crown-of-thorns starfish
#endif
!
!  Biological 2D Histrory variable IDs.
!
      integer, allocatable :: iHbio2(:)       ! 2D biological terms
#ifdef CORAL_POLYP
      integer  :: iClDOcoe (Ncl)
      integer  :: iClTAcal (Ncl)
      integer  :: iClTAcoe (Ncl)
      integer  :: iClDICcal(N_Csp,Ncl)
      integer  :: iClDICcoe(N_Csp,Ncl)
      integer  :: iClQC    (N_Csp,Ncl)
# if defined CORAL_NONE_CO2_EQ
      integer  :: iClCO2cal(N_Csp,Ncl)
      integer  :: iClCO2coe(N_Csp,Ncl)
# endif
# ifdef CORAL_ZOOXANTHELLAE
      integer  :: iClROS(Ncl)
      integer  :: iZxDns(Ncl)
      integer  :: iZxQC (N_Csp,Ncl)
      integer  :: iZxChl(Ncl)
      integer  :: iZxQAo(Ncl)
      integer  :: iZxQAr(Ncl)
      integer  :: iZxQAi(Ncl)
      integer  :: iZxQAid(Ncl)
# endif
# ifdef CORAL_SIZE_DYNAMICS

# endif
#endif
#ifdef SEAGRASS
      integer  :: iSgSgCBm(N_Csp,Nsg)  ! Seagrass leaf+root carbon-biomass per unit ground area (in seagrass habitat area) [umol.C m-2.sg.hab]
      integer  :: iSgSgNBm(N_Nsp,Nsg)  ! Seagrass leaf+root carbon-biomass per unit ground area (in seagrass habitat area) [umol.C m-2.sg.hab]
      integer  :: iSgSgPBm(N_Psp,Nsg)  ! Seagrass leaf+root carbon-biomass per unit ground area (in seagrass habitat area) [umol.C m-2.sg.hab]
      integer  :: iSgLfCBm(Nsg)        ! Seagrass leaf carbon-biomass per unit ground area (in seagrass habitat area) [umol.lf.C m-2.sg.hab]
      integer  :: iSgRtCBm(Nsg)        ! Seagrass root carbon-biomass per unit ground area (in seagrass habitat area) [umol.rt.C m-2.sg.hab]
      integer  :: iSgTotSgCBmS(Nsg)    ! SgTotSgCBm of last growth interval (For internal use only, need to save to restart file, but use SgTotSgCBm for output)
      integer  :: iSgTotSgCBm(Nsg)     ! Total seagrass carbon-biomass in grid [mol.C.tot]
      integer  :: iSgTotLfCBm(Nsg)     ! Total seagrass above ground carbon-biomass in grid [mol.C.lf]
      integer  :: iSgTotRtCBm(Nsg)     ! Total seagrass below ground carbon-biomass in grid [mol.C.rt]
      integer  :: iSgLAI(Nsg)          ! Leaf area index: one-sided green leaf area per unit ground surface area [m2.lf m-2.sg.hab]
      integer  :: iSgTotLA(Nsg)        ! Total one-sided green leaf area in grid [m2.lf]
      integer  :: iSgGridELAP(Nsg)     ! Effective leaf area projection on ground (whole grid) [m2.lf.proj m-2.grid]
      integer  :: iSgGridPhot(Nsg)     ! Seagrass gross photosynthesis rate per unit ground area (whole grid) [umol.C m-2.grid s-1]
      integer  :: iSgPhotLim(Nsg)      ! Seagrass photosynthesis limiting factor: 1 = light; 2 = Carbon uptake; 3 = Nitrogen uptake; 4 = Phosphorus uptake
      integer  :: iSgGridResp(Nsg)     ! Seagrass respiration rate per unit ground area (whole grid) [umol.C m-2.grid s-1]
      integer  :: iSgGridNetPhot(Nsg)  ! Seagrass net photosynthesis rate per unit ground area (whole grid) [umol.C m-2.grid s-1]
      integer  :: iSgGridDieoff(Nsg)   ! Seagrass dieoff rate carbon biomass per unit ground area (whole grid) [umol.C m-2.grid s-1]    
#endif
#ifdef MACROALGAE
      integer  :: iAgQC(N_Csp,Nag)
      integer  :: iAgQN(N_Nsp,Nag)
      integer  :: iAgQP(N_Psp,Nag)
#endif
!
!  Biological 3D Histrory variable IDs.
!
      integer, allocatable :: iHbio3(:)       ! 3D biological terms
!#ifdef CARBON_ISOTOPE
!      integer  :: id13C  ! d13C of total inorganic carbon  !!!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Remove??
!#endif

#if defined DIAGNOSTICS_BIO
!
!  Biological 2D Diagnostic variable IDs.
!
      integer, allocatable :: iDbio2(:)       ! 2D biological terms

      integer  :: iCO2fx                      ! air-sea CO2 flux
      integer  :: ipCO2                       ! partial pressure of CO2
      integer  :: iO2fx                       ! air-sea O2 flux
      integer  :: iPARb                       ! bottom photon flux density (umol m-2 s-1)
      integer  :: iTau_                       ! bottom shear stress (N m-2)

# ifdef CORAL_POLYP
      integer  :: iClPg(Ncl)
      integer  :: iCl_R(Ncl)
      integer  :: iCl_G(Ncl)
      integer  :: iClPn(Ncl)
#  ifdef CARBON_ISOTOPE
      integer  :: iClQCd13C(Ncl)
      integer  :: iCl_Gd13C(Ncl)
#  endif
#  ifdef CORAL_ZOOXANTHELLAE
      integer  :: iZxPg(Ncl)
      integer  :: iZx_R(Ncl)
      integer  :: iZxPn(Ncl)
#  endif
#  ifdef CORAL_SIZE_DYNAMICS
      integer  :: iClmt(Ncl)
      integer  :: iClgw(Ncl)
#  endif
# endif
# ifdef SEAGRASS
# endif
# ifdef MACROALGAE
      integer  :: iAgPg(Nag)                  ! Algal gross photosynthesis rate
      integer  :: iAg_R(Nag)                  ! Algal respiration rate
      integer  :: iAgPn(Nag)                  ! Algal net photosynthesis rate
#  ifdef CARBON_ISOTOPE
      integer  :: iAgQCd13C(Nag)
#  endif
#  ifdef NITROGEN_ISOTOPE
      integer  :: iAgQNd15N(Nag)
#  endif
# endif
!
!  Biological 3D Diagnostic variable IDs.
!
      integer, allocatable :: iDbio3(:)       ! 3D biological terms
      integer  :: ipHt_                       ! pH (total scale)
      integer  :: iWarg                       ! aragonite saturation state
      integer  :: iWcal                       ! calcite saturation state

!!! mons light model >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>KM:Add
# ifdef LIGHT_MODEL
      integer  :: iLight                      ! photon flux density
# endif
!!!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<KM:Add

# ifdef CARBON_ISOTOPE
      integer  :: iDICd13C                    ! d13C of total inorganic carbon
      integer  :: iDOCd13C(Ndom)              ! d13C of DOC
      integer  :: iPOCd13C(Npom)              ! d13C of POC
      integer  :: iPhyd13C(Nphy)              ! d13C of phytoplankton
      integer  :: iZood13C(Nzoo)              ! d13C of zooplankton
      integer  :: iPICd13C(Npim)              ! d13C of PIC
# endif
# ifdef NITROGEN_ISOTOPE
      integer  :: iNO3d15N                    ! d13C of NO3
      integer  :: iNH4d15N                    ! d13C of NH4
      integer  :: iDONd15N(Ndom)              ! d13C of DON
      integer  :: iPONd15N(Npom)              ! d13C of PON
      integer  :: iPhyd15N(Nphy)              ! d13C of phytoplankton
      integer  :: iZood15N(Nzoo)              ! d13C of zooplankton
# endif
#endif
!
!  Biological parameters.
!
      logical, allocatable :: LReadBioINI(:,:)       ! Switch to control reading of initial conditions from initial/restart nc file; 1 = foodweb (tracer variables); 2 = coral, seagass, macroalgae, sediment, etc.

      integer, allocatable :: CrlIter(:)
      integer, allocatable :: SedIter(:)

      real(r8), allocatable :: PARfrac(:)            ! nondimensional
      real(r8), allocatable :: pCO2air(:)            ! ppmv
      real(r8), allocatable :: DO_0 (:)              ! umol/L
      real(r8), allocatable :: TA_0 (:)              ! umol/kg
      real(r8), allocatable :: DIC_0(:)              ! umolC/kg
      real(r8), allocatable :: NO3_0(:)              ! umolN/L
      real(r8), allocatable :: NH4_0(:)              ! umolN/L
      real(r8), allocatable :: PO4_0(:)              ! umolP/L
      real(r8), allocatable :: DOC_0(:,:)            ! umolC/L
      real(r8), allocatable :: POC_0(:,:)            ! umolC/L
      real(r8), allocatable :: DON_0(:,:)            ! umolN/L
      real(r8), allocatable :: PON_0(:,:)            ! umolN/L
      real(r8), allocatable :: DOP_0(:,:)            ! umolP/L
      real(r8), allocatable :: POP_0(:,:)            ! umolP/L
      real(r8), allocatable :: PhyC_0(:,:)           ! umolC/L
      real(r8), allocatable :: ZooC_0(:,:)           ! umolC/L
      real(r8), allocatable :: PIC_0(:,:)            ! umolC/L
#if defined CARBON_ISOTOPE
      real(r8), allocatable :: d13C_DIC_0(:)         ! permil (VPDB)
      real(r8), allocatable :: d13C_DOC_0(:,:)       ! permil (VPDB)
      real(r8), allocatable :: d13C_POC_0(:,:)       ! permil (VPDB)
      real(r8), allocatable :: d13C_PhyC_0(:,:)      ! permil (VPDB)
      real(r8), allocatable :: d13C_ZooC_0(:,:)      ! permil (VPDB)
      real(r8), allocatable :: d13C_PIC_0(:,:)       ! permil (VPDB)
#endif
#if defined NITROGEN_ISOTOPE
      real(r8), allocatable :: d15N_NO3_0(:)         ! permil
      real(r8), allocatable :: d15N_NH4_0(:)         ! permil
      real(r8), allocatable :: d15N_DON_0(:,:)       ! permil
      real(r8), allocatable :: d15N_PON_0(:,:)       ! permil
      real(r8), allocatable :: d15N_PhyN_0(:,:)      ! permil
      real(r8), allocatable :: d15N_ZooN_0(:,:)      ! permil
#endif
#if defined COT_STARFISH
      real(r8), allocatable :: COTe0(:)              ! umolC/L
      real(r8), allocatable :: COTl0(:)              ! umolC/L
#endif

!!! yuta_edits_for_masa >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>YT:Add
#ifdef SEDIMENT_ECOSYS
!
!  Biological 3D Sediment Histrory variable IDs.
!
      integer, allocatable :: iHbiosed3(:)       ! 3D biological sediment terms

      integer :: iSdporo   !! Porosity (cm_w3 cm_s-3)
      integer :: iSdTmp    !! Temperature    (ºC)
      integer :: iSdSal    !! Salinity       (PSU)
      integer :: iSdO2     !! Dissolved Oxygen    (µmol l-1)
      integer :: iSdTA     !! Total Alkalinity
      integer :: iSdDIC(N_Csp)    !! Dissolved inorganic carbon
      integer :: iSdNO3(N_Nsp)     !! Nitrate     (µmol l-1)
      integer :: iSdNH4(N_Nsp)     !! Ammonium    (µmol l-1)
      integer :: iSdPO4(N_Psp)     !! Phosphate   (µmol l-1)
      integer :: iSdDOC(N_Csp,Ndom)    !! Dissolved organic carbon (µmol l-1)
      integer :: iSdPOC(N_Csp,Npom)    !! Particulate organic carbon (nmol g-1)
      integer :: iSdDON(N_Nsp,Ndom)    !! Dissolved organic nitrogen     (fast :Labile)      (µmol l-1)
      integer :: iSdPON(N_Nsp,Npom)    !! Particulate organic nitrogen   (fast :Labile)      (µmol l-1)
      integer :: iSdDOP(N_Psp,Ndom)    !! Dissolved organic phosphorus   (fast :Labile)      (µmol l-1)
      integer :: iSdPOP(N_Psp,Npom)    !! Particulate organic phosphorus (fast :Labile)      (µmol l-1)
      integer :: iSdMn2       !! Manganese ion        (µmol l-1)
      integer :: iSdMnO2      !! Manganese dioxide    (nmol g-1)
      integer :: iSdFe2       !! iron(II)          (µmol l-1)
      integer :: iSdFeS (N_Ssp)      !! iron sulfide      (nmol g-1)
      integer :: iSdFeS2(N_Ssp)      !! pyrite            (nmol g-1)
      integer :: iSdFeOOH     !! iron hydroxide    (nmol g-1)
      integer :: iSdFeOOH_PO4(N_Psp) !! iron-bound phosphate (FeOOH=PO43-)   (nmol g-1)
      integer :: iSdH2S(N_Ssp)       !! hydrogen sulfide         (µmol l-1)
      integer :: iSdSO4(N_Ssp)       !! sulfate   (µmol l-1)
      integer :: iSdS0 (N_Ssp)       !! sulfur    (nmol g-1)
#endif
!!!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<YT:Add

      CONTAINS

      SUBROUTINE initialize_biology
!
!=======================================================================
!                                                                      !
!  This routine sets several variables needed by the biology model.    !
!  It allocates and assigns biological tracers indices.                !
!                                                                      !
!=======================================================================

!
!  Local variable declarations
!
      integer :: i, j, ic
      integer :: isp, m

!
!-----------------------------------------------------------------------
!  Initialize tracer identification indices.
!-----------------------------------------------------------------------
!
      ic=NAT+NPT+NCS+NNS

      i=1
      iDO=ic+i
      i=i+1
      iTA=ic+i
      DO isp=1,N_Csp     
        i=i+1
        iDIC(isp)=ic+i
      END DO       
      DO isp=1,N_Nsp
        i=i+1     
        iNO3(isp)=ic+i
      END DO       
      DO isp=1,N_Nsp
        i=i+1    
        iNH4(isp)=ic+i       
      END DO       
      DO isp=1,N_Psp     
        i=i+1    
        iPO4(isp)=ic+i       
      END DO
      DO m=1,Ndom    
        DO isp=1,N_Csp     
          i=i+1    
          iDOC(isp,m)=ic+i
        END DO
      END DO 
      DO m=1,Ndom    
        DO isp=1,N_Nsp     
          i=i+1    
          iDON(isp,m)=ic+i 
        END DO
      END DO 
      DO m=1,Ndom    
        DO isp=1,N_Psp     
          i=i+1    
          iDOP(isp,m)=ic+i  
        END DO
      END DO 
      DO m=1,Npom    
        DO isp=1,N_Csp     
          i=i+1    
          iPOC(isp,m)=ic+i  
        END DO
      END DO 
      DO m=1,Npom    
        DO isp=1,N_Nsp     
          i=i+1    
          iPON(isp,m)=ic+i  
        END DO
      END DO 
      DO m=1,Npom    
        DO isp=1,N_Psp     
          i=i+1    
          iPOP(isp,m)=ic+i  
        END DO
      END DO 
      DO m=1,Nphy    
        DO isp=1,N_Csp     
          i=i+1    
          iPhyC(isp,m)=ic+i
        END DO
      END DO 
      DO m=1,Nphy    
        DO isp=1,N_Nsp     
          i=i+1    
          iPhyN(isp,m)=ic+i
        END DO
      END DO 
      DO m=1,Nphy    
        DO isp=1,N_Psp     
          i=i+1    
          iPhyP(isp,m)=ic+i
        END DO
      END DO 
      DO m=1,Nzoo    
        DO isp=1,N_Csp     
          i=i+1    
          iZooC(isp,m)=ic+i
        END DO
      END DO 
      DO m=1,Nzoo    
        DO isp=1,N_Nsp     
          i=i+1    
          iZooN(isp,m)=ic+i
        END DO
      END DO 
      DO m=1,Nzoo    
        DO isp=1,N_Psp     
          i=i+1    
          iZooP(isp,m)=ic+i
        END DO
      END DO 
      DO m=1,Npim    
        DO isp=1,N_Csp     
          i=i+1    
          iPIC(isp,m)=ic+i 
        END DO
      END DO 
#if defined COT_STARFISH
      i=i+1
      iCOTe=ic+i
      i=i+1
      iCOTl=ic+i
#endif
  
!-----------------------------------------------------------------------
!  Determine number of biological tracers.
!-----------------------------------------------------------------------

      NBT=i
!---------------------------------------------------------------------
!
!  Allocate biological tracer vector.
!
      IF (.not.allocated(idbio)) THEN
        allocate ( idbio(NBT) )
      END IF

      DO i=1,NBT
        idbio(i)=NAT+NPT+NCS+NNS+i
      END DO

!
!-----------------------------------------------------------------------
!  Set sources and sinks biology history parameters.
!-----------------------------------------------------------------------

!
!  Initialize 2D biology indices.
!
      ic=0     ! ic reset

#ifdef CORAL_POLYP
      DO m=1,Ncl
        ic=ic+1
        iClDOcoe(m)=ic
      END DO
      DO m=1,Ncl
        ic=ic+1
        iClTAcal(m)=ic
      END DO
      DO m=1,Ncl
        ic=ic+1
        iClTAcoe(m)=ic
      END DO
      DO m=1,Ncl
        DO isp=1,N_Csp     
          ic=ic+1
          iClDICcal(isp,m)=ic
        END DO
      END DO
      DO m=1,Ncl
        DO isp=1,N_Csp     
          ic=ic+1
          iClDICcoe(isp,m)=ic
        END DO
      END DO
      DO m=1,Ncl
        DO isp=1,N_Csp     
          ic=ic+1
          iClQC(isp,m)=ic
        END DO
      END DO
# if defined CORAL_NONE_CO2_EQ
      DO m=1,Ncl
        DO isp=1,N_Csp     
          ic=ic+1
          iClCO2cal(isp,m)=ic
        END DO
      END DO
      DO m=1,Ncl
        DO isp=1,N_Csp     
          ic=ic+1
          iClCO2coe(isp,m)=ic
        END DO
      END DO
# endif
# ifdef CORAL_ZOOXANTHELLAE
      DO m=1,Ncl
        ic=ic+1
        iClROS(m)=ic
      END DO
      DO m=1,Ncl
        ic=ic+1
        iZxDns(m)=ic
      END DO
      DO m=1,Ncl
        DO isp=1,N_Csp     
          ic=ic+1
          iZxQC(isp,m)=ic
        END DO
      END DO
      DO m=1,Ncl
        ic=ic+1
        iZxChl(m)=ic
      END DO
      DO m=1,Ncl
        ic=ic+1
        iZxQAo(m)=ic
      END DO
      DO m=1,Ncl
        ic=ic+1
        iZxQAr(m)=ic
      END DO
      DO m=1,Ncl
        ic=ic+1
        iZxQAi(m)=ic
      END DO
      DO m=1,Ncl
        ic=ic+1
        iZxQAid(m)=ic
      END DO
# endif
#endif
#ifdef SEAGRASS
      DO m=1,Nsg
        DO isp=1,N_Csp     
          ic=ic+1
          iSgSgCBm(isp,m)=ic
        END DO
      END DO
      DO m=1,Nsg
        DO isp=1,N_Nsp     
          ic=ic+1
          iSgSgNBm(isp,m)=ic
        END DO
      END DO
      DO m=1,Nsg
        DO isp=1,N_Psp     
          ic=ic+1
          iSgSgPBm(isp,m)=ic
        END DO
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgLfCBm(m)=ic
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgRtCBm(m)=ic
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgTotSgCBmS(m)=ic
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgTotSgCBm(m)=ic
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgTotLfCBm(m)=ic
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgTotRtCBm(m)=ic
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgLAI(m)=ic
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgTotLA(m)=ic
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgGridELAP(m)=ic
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgGridPhot(m)=ic
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgPhotLim(m)=ic
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgGridResp(m)=ic
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgGridNetPhot(m)=ic
      END DO
      DO m=1,Nsg
        ic=ic+1
        iSgGridDieoff(m)=ic
      END DO
#endif
#ifdef MACROALGAE
      DO m=1,Nag
        DO isp=1,N_Csp     
          ic=ic+1
          iAgQC(isp,m)=ic
        END DO
      END DO
      DO m=1,Nag
        DO isp=1,N_Nsp     
          ic=ic+1
          iAgQN(isp,m)=ic
        END DO
      END DO
      DO m=1,Nag
        DO isp=1,N_Psp     
          ic=ic+1
          iAgQP(isp,m)=ic
        END DO
      END DO

#endif
!
!  Set number of 2D history terms.
!
      NHbio2d=ic
!
!  Allocate biological history vectors
!
      IF (.not.allocated(iHbio2)) THEN
        allocate ( iHbio2(NHbio2d) )
      END IF

!----------------------------------------------------------------------
!  Initialize 3D biology indices.
!
      ic=0     ! ic reset
!#ifdef CARBON_ISOTOPE
!      ic=ic+1
!      id13C=ic  ! +1
!#endif

!  Set number of 3D history terms.
!
      NHbio3d=ic

      IF (.not.allocated(iHbio3)) THEN
        allocate ( iHbio3(NHbio3d) )
      END IF


!!! yuta_edits_for_masa >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>YT:Add
!----------------------------------------------------------------------
!  Initialize 3D biological sediment indices.
!
#ifdef SEDIMENT_ECOSYS  
      ic=0     ! ic reset

      ic=ic+1
      iSdporo=ic
      ic=ic+1
      iSdTmp=ic
      ic=ic+1
      iSdSal=ic
      ic=ic+1
      iSdO2=ic
      ic=ic+1
      iSdTA=ic
      DO isp=1,N_Csp     
        ic=ic+1
        iSdDIC(isp)=ic
      END DO
      DO isp=1,N_Nsp     
        ic=ic+1
        iSdNO3(isp)=ic
      END DO
      DO isp=1,N_Nsp     
        ic=ic+1
        iSdNH4(isp)=ic
      END DO
      DO isp=1,N_Psp     
        ic=ic+1
        iSdPO4(isp)=ic
      END DO
      DO m=1,Ndom
        DO isp=1,N_Csp     
          ic=ic+1
          iSdDOC(isp,m)=ic
        END DO
      END DO
      DO m=1,Npom
        DO isp=1,N_Csp     
          ic=ic+1
          iSdPOC(isp,m)=ic
        END DO
      END DO
      DO m=1,Ndom
        DO isp=1,N_Nsp     
          ic=ic+1
          iSdDON(isp,m)=ic
        END DO
      END DO
      DO m=1,Npom
        DO isp=1,N_Nsp     
          ic=ic+1
          iSdPON(isp,m)=ic
        END DO
      END DO
      DO m=1,Ndom
        DO isp=1,N_Psp     
          ic=ic+1
          iSdDOP(isp,m)=ic
        END DO
      END DO
      DO m=1,Npom
        DO isp=1,N_Psp     
          ic=ic+1
          iSdPOP(isp,m)=ic
        END DO
      END DO  
      ic=ic+1
      iSdMn2=ic
      ic=ic+1
      iSdMnO2=ic
      ic=ic+1
      iSdFe2=ic
      DO isp=1,N_Ssp     
        ic=ic+1
        iSdFeS(isp)=ic
      END DO
      DO isp=1,N_Ssp     
        ic=ic+1
        iSdFeS2(isp)=ic
      END DO
      ic=ic+1
      iSdFeOOH=ic
      DO isp=1,N_Psp     
        ic=ic+1
        iSdFeOOH_PO4(isp)=ic
      END DO
      DO isp=1,N_Ssp     
        ic=ic+1
        iSdH2S(isp)=ic
      END DO
      DO isp=1,N_Ssp     
        ic=ic+1
        iSdSO4(isp)=ic
      END DO
      DO isp=1,N_Ssp     
        ic=ic+1
        iSdS0(isp)=ic
      END DO  
!
!  Set number of 3D biological sediment history terms.
!
      NHbiosed3d=ic
!
!  Allocate biological history vectors
!
      IF (.not.allocated(iHbiosed3)) THEN
        allocate ( iHbiosed3(NHbiosed3d) )
      END IF

#endif
!!!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<YT:Add

#if defined DIAGNOSTICS_BIO
!
!-----------------------------------------------------------------------
!  Set sources and sinks biology diagnostic parameters.
!-----------------------------------------------------------------------

!
!  Initialize 2D biology indices.
!
      ic=0     ! ic reset

      ic=ic+1
      iCO2fx=ic
      ic=ic+1
      ipCO2=ic
      ic=ic+1
      iO2fx=ic

      ic=ic+1
      iPARb=ic

      ic=ic+1
      iTau_=ic

# ifdef CORAL_POLYP
      DO m=1,Ncl
        ic=ic+1
        iClPg(m)=ic
      END DO
      DO m=1,Ncl     
        ic=ic+1
        iCl_R(m)=ic
      END DO
      DO m=1,Ncl     
        ic=ic+1
        iCl_G(m)=ic
      END DO
      DO m=1,Ncl     
        ic=ic+1
        iClPn(m)=ic
      END DO
#  ifdef CARBON_ISOTOPE
      DO m=1,Ncl     
        ic=ic+1
        iClQCd13C(m)=ic
      END DO
      DO m=1,Ncl     
        ic=ic+1
        iCl_Gd13C(m)=ic
      END DO
#  endif
#  ifdef CORAL_ZOOXANTHELLAE
      DO m=1,Ncl     
        ic=ic+1
        iZxPg(m)=ic
      END DO
      DO m=1,Ncl     
        ic=ic+1
        iZx_R(m)=ic
      END DO
      DO m=1,Ncl     
        ic=ic+1
        iZxPn(m)=ic
      END DO
#  endif
#  ifdef CORAL_SIZE_DYNAMICS
      DO m=1,Ncl     
        ic=ic+1
        iClmt(m)=ic
      END DO
      DO m=1,Ncl     
        ic=ic+1
        iClgw(m)=ic
      END DO
#  endif
# endif
# ifdef SEAGRASS
      DO m=1,Nsg
      END DO
# endif
# ifdef MACROALGAE
      DO m=1,Nag
        ic=ic+1
        iAgPg(m)=ic
      END DO
      DO m=1,Nag
        ic=ic+1
        iAg_R(m)=ic
      END DO
      DO m=1,Nag
        ic=ic+1
        iAgPn(m)=ic
      END DO
#  ifdef CARBON_ISOTOPE
      DO m=1,Nag     
        ic=ic+1
        iAgQCd13C(m)=ic
      END DO
#  endif
#  ifdef NITROGEN_ISOTOPE
      DO m=1,Nag     
        ic=ic+1
        iAgQNd15N(m)=ic
      END DO
#  endif
# endif
!
!  Set number of 2D diagnostic terms.
!
      NDbio2d=ic
!
!  Allocate biological diagnostic vectors
!
      IF (.not.allocated(iDbio2)) THEN
        allocate ( iDbio2(NDbio2d) )
      END IF

!----------------------------------------------------------------------
!  Initialize 3D biology indices.
!
      ic=0     ! ic reset

      ic=ic+1
      ipHt_=ic
      ic=ic+1
      iWarg=ic
      ic=ic+1
      iWcal=ic

!!! mons light model >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>KM:Add
# ifdef LIGHT_MODEL
      ic=ic+1
      iLight=ic
# endif
!!!!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<KM:Add

# ifdef CARBON_ISOTOPE
      ic=ic+1
      iDICd13C=ic  ! +1
      DO m=1,Ndom
        ic=ic+1
        iDOCd13C(m)
      END DO
      DO m=1,Npom
        ic=ic+1
        iPOCd13C(m)
      END DO
      DO m=1,Nphy
        ic=ic+1
        iPhyd13C(m)
      END DO
      DO m=1,Nzoo
        ic=ic+1
        iZood13C(m)
      END DO
      DO m=1,Npim
        ic=ic+1
        iPICd13C(m)
      END DO
# endif
# ifdef NITROGEN_ISOTOPE
      ic=ic+1
      iNO3d15N=ic  ! +1
      ic=ic+1
      iNH4d15N=ic  ! +1
      DO m=1,Ndom
        ic=ic+1
        iDONd15N(m)
      END DO
      DO m=1,Npom
        ic=ic+1
        iPONd15N(m)
      END DO
      DO m=1,Nphy
        ic=ic+1
        iPhyd15N(m)
      END DO
      DO m=1,Nzoo
        ic=ic+1
        iZood15N(m)
      END DO
# endif

!  Set number of 3D diagnostic terms.
!
      NDbio3d=ic


      IF (.not.allocated(iDbio3)) THEN
        allocate ( iDbio3(NDbio3d) )
      END IF

#endif

!
!-----------------------------------------------------------------------
!  Allocate various module variables.
!-----------------------------------------------------------------------
!
      IF (.not.allocated(LReadBioINI)) THEN
        allocate ( LReadBioINI(2,Ngrids) )
      END IF
      IF (.not.allocated(CrlIter)) THEN
        allocate ( CrlIter(Ngrids) )
      END IF
      IF (.not.allocated(SedIter)) THEN
        allocate ( SedIter(Ngrids) )
      END IF
      IF (.not.allocated(PARfrac)) THEN
        allocate ( PARfrac(Ngrids) )
      END IF
      IF (.not.allocated(pCO2air)) THEN
        allocate ( pCO2air(Ngrids) )
      END IF
      IF (.not.allocated(DO_0)) THEN
        allocate ( DO_0(Ngrids) )
      END IF
      IF (.not.allocated(TA_0)) THEN
        allocate ( TA_0(Ngrids) )
      END IF
      IF (.not.allocated(DIC_0)) THEN
        allocate ( DIC_0(Ngrids) )
      END IF
      IF (.not.allocated(NO3_0)) THEN
        allocate ( NO3_0(Ngrids) )
      END IF
      IF (.not.allocated(NH4_0)) THEN
        allocate ( NH4_0(Ngrids) )
      END IF
      IF (.not.allocated(PO4_0)) THEN
        allocate ( PO4_0(Ngrids) )
      END IF
      IF (.not.allocated(DOC_0)) THEN
        allocate ( DOC_0(Ndom,Ngrids) )
      END IF
      IF (.not.allocated(POC_0)) THEN
        allocate ( POC_0(Npom,Ngrids) )
      END IF
      IF (.not.allocated(DON_0)) THEN
        allocate ( DON_0(Ndom,Ngrids) )
      END IF
      IF (.not.allocated(PON_0)) THEN
        allocate ( PON_0(Npom,Ngrids) )
      END IF
      IF (.not.allocated(DOP_0)) THEN
        allocate ( DOP_0(Ndom,Ngrids) )
      END IF
      IF (.not.allocated(POP_0)) THEN
        allocate ( POP_0(Npom,Ngrids) )
      END IF
      IF (.not.allocated(PhyC_0)) THEN
        allocate ( PhyC_0(Nphy,Ngrids) )
      END IF
      IF (.not.allocated(ZooC_0)) THEN
        allocate ( ZooC_0(Nzoo,Ngrids) )
      END IF
      IF (.not.allocated(PIC_0)) THEN
        allocate ( PIC_0(Npim,Ngrids) )
      END IF
#if defined CARBON_ISOTOPE
      IF (.not.allocated(d13C_DIC_0)) THEN
        allocate ( d13C_DIC_0(Ngrids) )
      END IF
      IF (.not.allocated(d13C_DOC_0)) THEN
        allocate ( d13C_DOC_0(Ndom,Ngrids) )
      END IF
      IF (.not.allocated(d13C_POC_0)) THEN
        allocate ( d13C_POC_0(Npom,Ngrids) )
      END IF
      IF (.not.allocated(d13C_PhyC_0)) THEN
        allocate ( d13C_PhyC_0(Nphy,Ngrids) )
      END IF
      IF (.not.allocated(d13C_ZooC_0)) THEN
        allocate ( d13C_ZooC_0(Nzoo,Ngrids) )
      END IF
      IF (.not.allocated(d13C_PIC_0)) THEN
        allocate ( d13C_PIC_0(Npim,Ngrids) )
      END IF
#endif
#if defined NITROGEN_ISOTOPE
      IF (.not.allocated(d15N_NO3_0)) THEN
        allocate ( d15N_NO3_0(Ngrids) )
      END IF
      IF (.not.allocated(d15N_NH4_0)) THEN
        allocate ( d15N_NH4_0(Ngrids) )
      END IF
      IF (.not.allocated(d15N_DON_0)) THEN
        allocate ( d15N_DON_0(Ndom,Ngrids) )
      END IF
      IF (.not.allocated(d15N_PON_0)) THEN
        allocate ( d15N_PON_0(Npom,Ngrids) )
      END IF
      IF (.not.allocated(d15N_PhyN_0)) THEN
        allocate ( d15N_PhyN_0(Nphy,Ngrids) )
      END IF
      IF (.not.allocated(d15N_ZooN_0)) THEN
        allocate ( d15N_ZooN_0(Nzoo,Ngrids) )
      END IF
#endif
#if defined COT_STARFISH
      IF (.not.allocated(COTe0)) THEN
        allocate ( COTe0(Ngrids) )
      END IF
      IF (.not.allocated(COTl0)) THEN
        allocate ( COTl0(Ngrids) )
      END IF
#endif
      RETURN
      END SUBROUTINE initialize_biology

!***********************************************************************

      SUBROUTINE send_roms_his2reef_ecosys(ng,LBi, UBi, LBj, UBj)
!
!=======================================================================
!                                                                      !
!  This routine sets reef_ecosys arrays to roms arrays for             !
!  his nc input.                                                       !
!  This routine is called in get_state.F and only used for initial     !
!  condition setting.                                                  !
!                                                                      !
!=======================================================================
!
!  Imported variable declarations.
!
      integer, intent(in) :: ng, LBi, UBi, LBj, UBj
!
!  Local variable declarations.
!
      integer :: i,j,k
      integer :: isp,m

!-----------------------------------------------------------------------
      DO j=LBj, UBj
        DO i=LBi, UBi
#ifdef CORAL_POLYP
          DO m=1,Ncl
            !  :  (To be updated)
            CORAL(ng)%DOcoe(m,i,j)    = OCEAN(ng)%HisBio2d(i,j, iClDOcoe (m) )
            CORAL(ng)%TAcal(m,i,j)    = OCEAN(ng)%HisBio2d(i,j, iClTAcal (m) )
            CORAL(ng)%TAcoe(m,i,j)    = OCEAN(ng)%HisBio2d(i,j, iClTAcoe (m) )
            CORAL(ng)%DICcal(:,m,i,j) = OCEAN(ng)%HisBio2d(i,j, iClDICcal(1,m):iClDICcal(N_Csp,m) )
            CORAL(ng)%DICcoe(:,m,i,j) = OCEAN(ng)%HisBio2d(i,j, iClDICcoe(1,m):iClDICcoe(N_Csp,m) )
            CORAL(ng)%QC    (:,m,i,j) = OCEAN(ng)%HisBio2d(i,j, iClQC    (1,m):iClQC    (N_Csp,m) )
# if defined CORAL_NONE_CO2_EQ
            CORAL(ng)%CO2cal(:,m,i,j) = OCEAN(ng)%HisBio2d(i,j, iClCO2cal(1,m):iClCO2cal(N_Csp,m) )
            CORAL(ng)%CO2coe(:,m,i,j) = OCEAN(ng)%HisBio2d(i,j, iClCO2coe(1,m):iClCO2coe(N_Csp,m) )
# endif
# if defined CORAL_ZOOXANTHELLAE
            CORAL(ng)%ROS(m,i,j) = OCEAN(ng)%HisBio2d(i,j, iClROS(m) )
# endif
# if defined CORAL_NUTRIENTS
            !  :  (To be updated)
# endif     
# if defined CORAL_SIZE_DYNAMICS
            !  :  (To be updated)
# endif

# if defined CORAL_ZOOXANTHELLAE
            ZOOX(ng)%dens(m,i,j) = OCEAN(ng)%HisBio2d(i,j, iZxDns(m) )
            ZOOX(ng)%QC(:,m,i,j) = OCEAN(ng)%HisBio2d(i,j, iZxQC (1,m):iZxQC (N_Csp,m) )
            ZOOX(ng)%Chl (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iZxChl(m) )
            ZOOX(ng)%QAo (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iZxQAo(m) )
            ZOOX(ng)%QAr (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iZxQAr(m) )
            ZOOX(ng)%QAi (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iZxQAi(m) )
!            ZOOX(ng)%QAid(m,i,j) = OCEAN(ng)%HisBio2d(i,j, iZxQAid(m) )
#  if defined CORAL_NUTRIENTS
            !  :  (To be updated)
#  endif
# endif
          END DO
#endif

#ifdef SEAGRASS  
          DO m=1,Nsg
            SGRASS(ng)%SgCBmF   (:,m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgSgCBm(1,m):iSgSgCBm(N_Csp,m) )
            SGRASS(ng)%SgNBmF   (:,m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgSgNBm(1,m):iSgSgNBm(N_Nsp,m) )
            SGRASS(ng)%SgPBmF   (:,m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgSgPBm(1,m):iSgSgPBm(N_Psp,m) )
            SGRASS(ng)%LfCBm      (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgLfCBm      (m) )
            SGRASS(ng)%RtCBm      (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgRtCBm      (m) )
            SGRASS(ng)%TotSgCBm   (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgTotSgCBmS  (m) )
            SGRASS(ng)%TotSgCBmF  (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgTotSgCBm   (m) )
            SGRASS(ng)%TotLfCBm   (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgTotLfCBm   (m) )
            SGRASS(ng)%TotRtCBm   (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgTotRtCBm   (m) )
            SGRASS(ng)%LAI        (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgLAI        (m) )
            SGRASS(ng)%TotLA      (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgTotLA      (m) )
            SGRASS(ng)%GridELAP   (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgGridELAP   (m) )
            SGRASS(ng)%GridPhot   (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgGridPhot   (m) )
            SGRASS(ng)%PhotLim    (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgPhotLim    (m) )
            SGRASS(ng)%GridResp   (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgGridResp   (m) )
            SGRASS(ng)%GridNetPhot(m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgGridNetPhot(m) )
            SGRASS(ng)%GridDieoff (m,i,j) = OCEAN(ng)%HisBio2d(i,j, iSgGridDieoff (m) )
          END DO
#endif
#ifdef MACROALGAE  
          DO m=1,Nag
          !  :  (To be updated)
          END DO
#endif
        END DO
      END DO

#ifdef SEDIMENT_ECOSYS  
      DO j=LBj, UBj
        DO i=LBi, UBi
          DO k=1,Nsed
            SEDECO(ng)%poro(k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdporo) 
            SEDECO(ng)%Tmp (k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdTmp ) 
            SEDECO(ng)%Sal (k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdSal ) 
            SEDECO(ng)%O2  (k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdO2  ) 
            SEDECO(ng)%TA  (k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdTA  ) 
            SEDECO(ng)%DIC (:,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdDIC(1):iSdDIC(N_Csp) ) 
            SEDECO(ng)%NO3 (:,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdNO3(1):iSdNO3(N_Nsp) ) 
            SEDECO(ng)%NH4 (:,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdNH4(1):iSdNH4(N_Nsp) ) 
            SEDECO(ng)%PO4 (:,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdPO4(1):iSdPO4(N_Psp) ) 
            DO m=1,Ndom
              SEDECO(ng)%DOC (:,m,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdDOC(1,m):iSdDOC(N_Csp,m) )
              SEDECO(ng)%DON (:,m,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdDON(1,m):iSdDON(N_Nsp,m) ) 
              SEDECO(ng)%DOP (:,m,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdDOP(1,m):iSdDOP(N_Psp,m) ) 
            END DO 
            DO m=1,Npom
              SEDECO(ng)%POC (:,m,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdPOC(1,m):iSdPOC(N_Csp,m) ) 
              SEDECO(ng)%PON (:,m,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdPON(1,m):iSdPON(N_Nsp,m) ) 
              SEDECO(ng)%POP (:,m,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdPOP(1,m):iSdPOP(N_Psp,m) ) 
            END DO 
            SEDECO(ng)%Mn2 (k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdMn2 ) 
            SEDECO(ng)%MnO2(k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdMnO2) 
            SEDECO(ng)%Fe2 (k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdFe2 ) 
            SEDECO(ng)%FeS (:,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdFeS (1):iSdFeS (N_Ssp)) 
            SEDECO(ng)%FeS2(:,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdFeS2(1):iSdFeS2(N_Ssp)) 
            SEDECO(ng)%FeOOH    (k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdFeOOH ) 
            SEDECO(ng)%FeOOH_PO4(:,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdFeOOH_PO4(1):iSdFeOOH_PO4(N_Psp)) 
            SEDECO(ng)%H2S (:,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdH2S(1):iSdH2S(N_Ssp) )
            SEDECO(ng)%SO4 (:,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdSO4(1):iSdSO4(N_Ssp) )
            SEDECO(ng)%S0  (:,k,i,j) = OCEAN(ng)%HisBiosed3d(i,j,k,iSdS0 (1):iSdS0 (N_Ssp) )
          END DO
        END DO
      END DO
#endif
      END SUBROUTINE send_roms_his2reef_ecosys

!***********************************************************************

      SUBROUTINE send_reef_ecosys2roms_his(ng,LBi, UBi, LBj, UBj)
!
!=======================================================================
!                                                                      !
!  This routine sets reef_ecosys arrays to roms arrays for             !
!  his nc output.                                                      !
!  This routine is called in mod_arrays.F and only used for initial    !
!  condition setting.                                                  !
!                                                                      !
!=======================================================================
!
!  Imported variable declarations.
!
      integer, intent(in) :: ng, LBi, UBi, LBj, UBj
!
!  Local variable declarations.
!
      integer :: i,j,k,m
      integer :: isp

!-----------------------------------------------------------------------
      DO j=LBj, UBj
        DO i=LBi, UBi
#ifdef CORAL_POLYP
          DO m=1,Ncl
            !  :  (To be updated)
            OCEAN(ng)%HisBio2d(i,j, iClDOcoe (m) ) = CORAL(ng)%DOcoe(m,i,j) 
            OCEAN(ng)%HisBio2d(i,j, iClTAcal (m) ) = CORAL(ng)%TAcal(m,i,j) 
            OCEAN(ng)%HisBio2d(i,j, iClTAcoe (m) ) = CORAL(ng)%TAcoe(m,i,j) 
            OCEAN(ng)%HisBio2d(i,j, iClDICcal(1,m):iClDICcal(N_Csp,m) ) = CORAL(ng)%DICcal(:,m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iClDICcoe(1,m):iClDICcoe(N_Csp,m) ) = CORAL(ng)%DICcoe(:,m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iClQC    (1,m):iClQC    (N_Csp,m) ) = CORAL(ng)%QC    (:,m,i,j)    
# if defined CORAL_NONE_CO2_EQ
            OCEAN(ng)%HisBio2d(i,j, iClCO2cal(1,m):iClCO2cal(N_Csp,m) ) = CORAL(ng)%CO2cal(:,m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iClCO2coe(1,m):iClCO2coe(N_Csp,m) ) = CORAL(ng)%CO2coe(:,m,i,j)
# endif
# if defined CORAL_ZOOXANTHELLAE
            OCEAN(ng)%HisBio2d(i,j, iClROS(m) ) = CORAL(ng)%ROS(m,i,j) 
# endif
# if defined CORAL_NUTRIENTS
            !  :  (To be updated)
# endif     
# if defined CORAL_SIZE_DYNAMICS
            !  :  (To be updated)
# endif

# if defined CORAL_ZOOXANTHELLAE
            OCEAN(ng)%HisBio2d(i,j, iZxDns(m) ) = ZOOX(ng)%dens(m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iZxQC (1,m):iZxQC (N_Csp,m) ) = ZOOX(ng)%QC(:,m,i,j)  
            OCEAN(ng)%HisBio2d(i,j, iZxChl(m) ) = ZOOX(ng)%Chl(m,i,j) 
            OCEAN(ng)%HisBio2d(i,j, iZxQAo(m) ) = ZOOX(ng)%QAo(m,i,j) 
            OCEAN(ng)%HisBio2d(i,j, iZxQAr(m) ) = ZOOX(ng)%QAr(m,i,j) 
            OCEAN(ng)%HisBio2d(i,j, iZxQAi(m) ) = ZOOX(ng)%QAi(m,i,j) 
!            OCEAN(ng)%HisBio2d(i,j, iZxQAid(m) )= ZOOX(ng)%QAid(m,i,j)
#  if defined CARBON_ISOTOPE
            OCEAN(ng)%HisBio2d(i,j, iZxQ13C(m) ) = ZOOX(ng)%Q13C(m,i,j) 
#  endif
#  if defined CORAL_NUTRIENTS
            !  :  (To be updated)
#  endif
# endif
          END DO
#endif
#ifdef SEAGRASS
          DO m=1,Nsg
            OCEAN(ng)%HisBio2d(i,j, iSgSgCBm(1,m):iSgSgCBm(N_Csp,m) ) = SGRASS(ng)%SgCBmF(:,m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgSgNBm(1,m):iSgSgNBm(N_Nsp,m) ) = SGRASS(ng)%SgCBmF(:,m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgSgPBm(1,m):iSgSgPBm(N_Psp,m) ) = SGRASS(ng)%SgCBmF(:,m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgLfCBm      (m) ) = SGRASS(ng)%LfCBm      (m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgRtCBm      (m) ) = SGRASS(ng)%RtCBm      (m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgTotSgCBmS  (m) ) = SGRASS(ng)%TotSgCBm   (m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgTotSgCBm   (m) ) = SGRASS(ng)%TotSgCBmF  (m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgTotLfCBm   (m) ) = SGRASS(ng)%TotLfCBm   (m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgTotRtCBm   (m) ) = SGRASS(ng)%TotRtCBm   (m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgLAI        (m) ) = SGRASS(ng)%LAI        (m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgTotLA      (m) ) = SGRASS(ng)%TotLA      (m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgGridELAP   (m) ) = SGRASS(ng)%GridELAP   (m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgGridPhot   (m) ) = SGRASS(ng)%GridPhot   (m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgPhotLim    (m) ) = SGRASS(ng)%PhotLim    (m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgGridResp   (m) ) = SGRASS(ng)%GridResp   (m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgGridNetPhot(m) ) = SGRASS(ng)%GridNetPhot(m,i,j)
            OCEAN(ng)%HisBio2d(i,j, iSgGridDieoff (m) ) = SGRASS(ng)%GridDieoff (m,i,j)
          END DO
#endif
#ifdef MACROALGAE
          DO m=1,Nag
          !  :  (To be updated)
          END DO
#endif
        END DO
      END DO

#ifdef SEDIMENT_ECOSYS  
      DO j=LBj, UBj
        DO i=LBi, UBi
          DO k=1,Nsed
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdporo) = SEDECO(ng)%poro(k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdTmp ) = SEDECO(ng)%Tmp (k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdSal ) = SEDECO(ng)%Sal (k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdO2  ) = SEDECO(ng)%O2  (k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdTA  ) = SEDECO(ng)%TA  (k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdDIC(1):iSdDIC(N_Csp) ) = SEDECO(ng)%DIC (:,k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdNO3(1):iSdNO3(N_Nsp) ) = SEDECO(ng)%NO3 (:,k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdNH4(1):iSdNH4(N_Nsp) ) = SEDECO(ng)%NH4 (:,k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdPO4(1):iSdPO4(N_Psp) ) = SEDECO(ng)%PO4 (:,k,i,j)
            DO m=1,Ndom
              OCEAN(ng)%HisBiosed3d(i,j,k,iSdDOC(1,m):iSdDOC(N_Csp,m) ) = SEDECO(ng)%DOC (:,m,k,i,j)
              OCEAN(ng)%HisBiosed3d(i,j,k,iSdDON(1,m):iSdDON(N_Nsp,m) ) = SEDECO(ng)%DON (:,m,k,i,j)
              OCEAN(ng)%HisBiosed3d(i,j,k,iSdDOP(1,m):iSdDOP(N_Psp,m) ) = SEDECO(ng)%DOP (:,m,k,i,j)
            END DO 
            DO m=1,Npom
              OCEAN(ng)%HisBiosed3d(i,j,k,iSdPOC(1,m):iSdPOC(N_Csp,m) ) = SEDECO(ng)%POC (:,m,k,i,j)
              OCEAN(ng)%HisBiosed3d(i,j,k,iSdPON(1,m):iSdPON(N_Nsp,m) ) = SEDECO(ng)%PON (:,m,k,i,j)
              OCEAN(ng)%HisBiosed3d(i,j,k,iSdPOP(1,m):iSdPOP(N_Psp,m) ) = SEDECO(ng)%POP (:,m,k,i,j)
            END DO 
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdMn2 ) = SEDECO(ng)%Mn2 (k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdMnO2) = SEDECO(ng)%MnO2(k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdFe2 ) = SEDECO(ng)%Fe2 (k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdFeS (1):iSdFeS (N_Ssp)) = SEDECO(ng)%FeS (:,k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdFeS2(1):iSdFeS2(N_Ssp)) = SEDECO(ng)%FeS2(:,k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdFeOOH    ) = SEDECO(ng)%FeOOH    (k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdFeOOH_PO4(1):iSdFeOOH_PO4(N_Psp)) = SEDECO(ng)%FeOOH_PO4(:,k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdH2S(1):iSdH2S(N_Ssp) ) = SEDECO(ng)%H2S (:,k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdSO4(1):iSdSO4(N_Ssp) ) = SEDECO(ng)%SO4 (:,k,i,j)
            OCEAN(ng)%HisBiosed3d(i,j,k,iSdS0 (1):iSdS0 (N_Ssp) ) = SEDECO(ng)%S0  (:,k,i,j)
          END DO
        END DO
      END DO
#endif
      END SUBROUTINE send_reef_ecosys2roms_his

!***********************************************************************
#if defined DIAGNOSTICS_BIO

      SUBROUTINE send_reef_ecosys2roms_dia(ng,LBi, UBi, LBj, UBj)
!
!=======================================================================
!                                                                      !
!  This routine sets reef_ecosys arraies to roms arralies for          !
!  his nc output.                                                      !
!  This routine is called in mod_arrays.F and only used for initial    !
!  condotion setting.                                                  !
!                                                                      !
!=======================================================================

      USE mod_geochem
      USE mod_diags
!
!  Imported variable declarations.
!
      integer, intent(in) :: ng, LBi, UBi, LBj, UBj
!
!  Local variable declarations.
!
      integer :: i,j,k
      integer :: isp,m
      real(r8) :: tmp

!-----------------------------------------------------------------------
      DO j=LBj, UBj
        DO i=LBi, UBi
# ifdef CORAL_POLYP
          DO m=1,Ncl
            !  :  (To be updated)
            DIAGS(ng)%DiaBio2d(i,j, iClPg(m) ) = CORAL(ng)%Pg(m,i,j) 
            DIAGS(ng)%DiaBio2d(i,j, iCl_R(m) ) = CORAL(ng)%R (m,i,j) 
            DIAGS(ng)%DiaBio2d(i,j, iCl_G(m) ) = CORAL(ng)%G (m,i,j)
            DIAGS(ng)%DiaBio2d(i,j, iClPn(m) ) = CORAL(ng)%Pg(m,i,j)-CORAL(ng)%R (m,i,j)
#  if defined CARBON_ISOTOPE
            tmp = CORAL(ng)%Q13C(m,i,j) / CORAL(ng)%QC(m,i,j)   !coral organism
            DIAGS(ng)%DiaBio2d(i,j, iClQCd13C(m) ) = d13C_fromR13C(tmp)
#   if defined CORAL_NONE_CO2_EQ
            !  :  (To be updated)
#   endif
#  endif
#  if defined CORAL_ZOOXANTHELLAE
            !  :  (To be updated)
#  endif
#  if defined CORAL_NUTRIENTS
            !  :  (To be updated)
#  endif     
#  if defined CORAL_SIZE_DYNAMICS
            DIAGS(ng)%DiaBio2d(i,j, iClmt(m) ) = CORAL(ng)%mort(m,i,j) 
            DIAGS(ng)%DiaBio2d(i,j, iClgw(m) ) = CORAL(ng)%growth(m,i,j) 
#  endif

#  if defined CORAL_ZOOXANTHELLAE
            !  :  (To be updated)
#   if defined CARBON_ISOTOPE
            !  :  (To be updated)
#   endif
#   if defined CORAL_NUTRIENTS
            !  :  (To be updated)
#   endif
#  endif
          END DO
# endif

# ifdef SEAGRASS
          DO m=1,Nsg
          END DO
# endif

# ifdef MACROALGAE
          DO m=1,Nag
            DIAGS(ng)%DiaBio2d(i,j, iAgPg(m) ) = ALGAE(ng)%Pg(m,i,j)
            DIAGS(ng)%DiaBio2d(i,j, iAg_R(m) ) = ALGAE(ng)%R (m,i,j)
            DIAGS(ng)%DiaBio2d(i,j, iAgPn(m) ) = ALGAE(ng)%Pg(m,i,j)-ALGAE(ng)%R (m,i,j)
          END DO
# endif
        END DO
      END DO

# ifdef SEDIMENT_ECOSYS  
      DO k=1,Nsed
        DO j=LBj, UBj
          DO i=LBi, UBi
            !  :  (To be updated)
          END DO
        END DO
      END DO
# endif

      END SUBROUTINE send_reef_ecosys2roms_dia
#endif

!!! yuta_edits >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>YT:Add
#ifdef REEF_ECOSYS
      ! yt_edit this subroutine wraps the logic for getting tile bounds and ROMS inputs with the actual initialize_reef_ecosys() call
      SUBROUTINE call_initialize_reef_ecosys_wrapper(ng, tile)
      
      USE mod_grid,         ONLY : GRID
      USE mod_reef_ecosys,  ONLY : initialize_reef_ecosys

      implicit none
      integer, intent(in) :: ng, tile
      integer :: i, j
      integer :: LBi, UBi, LBj, UBj
      !
# include "set_bounds.h"
      !
      !  Set array initialization range.
      !
      LBi=BOUNDS(ng)%LBi(tile)
      UBi=BOUNDS(ng)%UBi(tile)
      LBj=BOUNDS(ng)%LBj(tile)
      UBj=BOUNDS(ng)%UBj(tile)

      CALL initialize_reef_ecosys(ng, IstrR, IendR, JstrR, JendR   &
          , .not. LReadBioINI(2,ng)                                &   ! TRUE = initialize coral, seagass, macroalgae, sediment from start; FALSE = continue from previous run
# ifdef SEAGRASS
          , GRID(ng)%om_r(IstrR:IendR,JstrR:JendR)                 &   ! grid size XI-direction (meters)
          , GRID(ng)%on_r(IstrR:IendR,JstrR:JendR)                 &   ! grid size ETA-direction (meters)
          , GRID(ng)%p_sgrass(Nsg,IstrR:IendR,JstrR:JendR)         &   ! seagrass coverage (habitat area in grid / grid area)
# endif
          )

      CALL send_reef_ecosys2roms_his (ng, LBi, UBi, LBj, UBj)
      write(*,*) 'yt_debug: mod_reef_ecosys.F initialize_reef_ecosys() finished send_reef_ecosys2roms_his'
    
      END SUBROUTINE call_initialize_reef_ecosys_wrapper
#endif
!!!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<YT:Add

