# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./PreProcessor/SDECTriaxialTest
# Target is a library:  

LIBS += -lBodyMacroParameters \
        -lElasticContactLaw \
        -lMacroMicroElasticRelationships \
        -lSDECTimeStepper \
        -lPhysicalActionVectorVector \
        -lInteractionVecSet \
        -lBodyRedirectionVector \
        -lInteractingSphere \
        -lInteractingBox \
        -lCundallNonViscousMomentumDamping \
        -lCundallNonViscousForceDamping \
        -lPhysicalActionContainerReseter \
        -lInteractionGeometryMetaEngine \
        -lInteractionPhysicsMetaEngine \
        -lBoundingVolumeMetaEngine \
        -lPersistentSAPCollider \
        -lAABB \
        -lSphere \
        -lBox \
        -lInteractionDescriptionSet2AABB \
        -rdynamic 
INCLUDEPATH += ../../Engine/StandAloneEngine/SDECTimeStepper \
               ../../Engine/StandAloneEngine/ElasticContactLaw \
               ../../Engine/EngineUnit/MacroMicroElasticRelationships \
               ../../DataClass/PhysicalParameters/BodyMacroParameters 
QMAKE_LIBDIR = ../../../../bin \
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
HEADERS += SDECTriaxialTest.hpp 
SOURCES += SDECTriaxialTest.cpp 
