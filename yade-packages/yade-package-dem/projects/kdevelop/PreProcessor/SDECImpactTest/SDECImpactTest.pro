# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./PreProcessor/SDECImpactTest
# Target is a library:  

LIBS += -lSDECLinkGeometry \
        -lElasticContactLaw \
        -lAveragePositionRecorder \
        -lVelocityRecorder \
        -lForceRecorder \
        -lMacroMicroElasticRelationships \
        -lSDECTimeStepper \
        -lPhysicalActionVectorVector \
        -lInteractionVecSet \
        -lBodyRedirectionVector \
        -lyade-lib-wm3-math \
        -lInteractingSphere \
        -lInteractingBox \
        -lCundallNonViscousMomentumDamping \
        -lCundallNonViscousForceDamping \
        -lMetaInteractingGeometry \
        -lGravityEngine \
        -lyade-lib-serialization \
        -lPhysicalActionContainerInitializer \
        -lPhysicalActionContainerReseter \
        -lInteractionGeometryMetaEngine \
        -lInteractionPhysicsMetaEngine \
        -lPhysicalActionApplier \
        -lPhysicalParametersMetaEngine \
        -lBoundingVolumeMetaEngine \
        -lyade-lib-multimethods \
        -lBox \
        -lSphere \
        -lAABB \
        -lPersistentSAPCollider \
        -lSAPCollider \
        -lInteractionDescriptionSet2AABB \
        -rdynamic 
INCLUDEPATH += ../../Engine/StandAloneEngine/VelocityRecorder \
               ../../Engine/StandAloneEngine/ForceRecorder \
               ../../Engine/StandAloneEngine/AveragePositionRecorder \
               ../../Engine/StandAloneEngine/SDECTimeStepper \
               ../../Engine/StandAloneEngine/ElasticContactLaw \
               ../../Engine/EngineUnit/MacroMicroElasticRelationships \
               ../../DataClass/InteractionPhysics/SDECLinkPhysics \
               ../../DataClass/InteractionGeometry/SDECLinkGeometry \
               ../../DataClass/PhysicalParameters/BodyMacroParameters 
QMAKE_LIBDIR = ../../../../bin \
               ../../../../bin \
               ../../../../bin \
               ../../../../bin \
               ../../../../bin \
               ../../../../bin \
               ../../../../bin \
               /usr/local/lib/yade/yade-package-common/ \
               /usr/local/lib/yade/yade-libs/ 
QMAKE_CXXFLAGS_RELEASE += -lpthread \
                          -pthread 
QMAKE_CXXFLAGS_DEBUG += -lpthread \
                        -pthread 
DESTDIR = ../../../../bin 
CONFIG += debug \
          warn_on \
          dll 
TEMPLATE = lib 
HEADERS += SDECImpactTest.hpp 
SOURCES += SDECImpactTest.cpp 
