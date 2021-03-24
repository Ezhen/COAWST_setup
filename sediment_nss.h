/*
** svn $Id: ns.h 838 2008-11-17 04:22:18Z eivanov $
*******************************************************************************
** Copyright (c) 2002-2008 The ROMS/TOMS Group                               **
**   Licensed under a MIT/X style license                                    **
**   See License_ROMS.txt                                                    **
*******************************************************************************
**
** Options for Inlet Test Case, waves-ocean (SWAN/ROMS) two-way coupling.
**
** Application flag:   NSS
** Input script:       ocean_ns.in
**                     coupling_ns.in
*/

/* MAIN OPTIONS */

#define ROMS_MODEL

/* WAVE */
#define SWAN_MODEL
#define MCT_LIB
#if defined SWAN_MODEL
#  define WEC_VF
#  define WDISS_WAVEMOD
#  define SSW_BBL
#  define SSW_CALC_ZNOT
# else
# define UV_LOGDRAG
# endif

#define MPI_REAL8 MPI_DOUBLE_PRECISION



/* GRID NESTING OPTIONS */

#define NESTING			/* activate grid nesting: composite/refinement */
#undef ONE_WAY			/* one-way nesting in refinement grids */


/* HORIZONTAL AND VERTICAL ADVECTION OF MOMENTUM */

#define UV_ADV			/* advection terms */	
#define UV_COR			/* Coriolis term */
#define UV_VIS2			/* harmonic Laplacian horizontal mixing */
#define SPLINES_VVISC		/* splines reconstruction of vertical viscosity */
#define SPLINES_VDIFF


/* HORIZONTAL AND VERTICAL ADVECTION OF TRACERS */

#define CURVGRID
/*#define TS_MPDATA*/
#define TS_HSIMT
#define TS_DIF2			/* harmonic horizontal mixing */
#define NONLIN_EOS     		/* define if using nonlinear equation of state */
#define SALINITY		/* using salinity */


/* PRESSURE GRADIENT ALGORYTHM OPTIONS */

#define DJ_GRADPS		/* Splines density  Jacobian (Shchepetkin, 2000) */
				/* if everything is undefined, standard density Jacobian algorithm will be used to compute prussure gradient term */


/* SURFACE BOUNDARY FLUXES */

#define BULK_FLUXES
#define EMINUSP
#define LONGWAVE
#define SOLAR_SOURCE
#define COOL_SKIN



/* MODEL CONFGURATION OPTIONS */

#define SOLVE3D			/* solving 3D primitive equations */
#define MASKING			/* define if there is land in the domain */
#define AVERAGES		/* writing out NLM time-averaged data */


/* ANALYTICAL FIELDS CONFIGURATIONS */
#define ANA_BSFLUX		/* analytical bottom salinity flux */
#define ANA_BTFLUX		/* analytical bottom temperature flux */


/* HORIZONTAL MIXING OF MOMENTUM */

#define MIX_S_UV		/* mixing along constant S-surfaces 	(defined for NEST8 and NEST9) */


/* HORIZONTAL MIXING OF TRACERS */

# define MIX_GEO_TS


/* VERTICAL TURBULENT MIXING SCHEME AND ITS OPTIONS */

/* Turbulence closure */
# define GLS_MIXING

# if defined GLS_MIXING || defined MY25_MIXING
#  define KANTHA_CLAYSON
#  define N2S2_HORAVG
#  define RI_SPLINES
# endif

/* TIDAL FORCING AT THE OPEN BOUNDARIES */

#define SSH_TIDES		/* imposing tidal elevation */
#define UV_TIDES		/* imposing tidal currents */
#define ADD_FSOBC		/* tidal elevation to processed OBC data */
#define ADD_M2OBC		/* tidal currents  to processed OBC data */
#define WET_DRY			/* wetting and drying */


/* SEDIMENT OPTIONS */
#define SEDIMENT
# if defined SEDIMENT
#  undef MIXED_BED 
# undef SED_TAU_CD_LIN
# define  SED_TAU_CD_CONST
#  define COHESIVE_BED
#  define SUSPLOAD
#  undef ANA_SPFLUX
#  define ANA_BPFLUX
#  define SED_BIODIFF
# define SED_DENS
# undef SED_MORPH
# endif

# undef ANA_SEDIMENT

