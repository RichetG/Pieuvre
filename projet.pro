# The <code>animate()</code> function illustrated by a water particle simulation.

# When animation is activated (the Return key toggles animation), the <code>animate()</code> and
# then the <code>draw()</code> functions are called in an infinite loop.

# You can tune the frequency of your animation (default is 25Hz) using
# <code>setAnimationInterval()</code>. The frame rate will then be fixed, provided that your
# animation loop function is fast enough.

TEMPLATE = app
TARGET   = animation

HEADERS  = \
    vertex.h \
    face.h \
    normale.h \
    texture.h \
    tripletface.h \
    joint.h \
    projet.h \
    GloveAcquisitor/DataGloveReceiver/DataGloveReceiver.h \
    GloveAcquisitor/DataGloveSender/DataGloveSender.h \
    GloveAcquisitor/CoordinateConverter/CoordinateConverter.h \
    ik.h
SOURCES  = main.cpp \
    vertex.cpp \
    normale.cpp \
    face.cpp \
    tripletface.cpp \
    texture.cpp \
    joint.cpp \
    projet.cpp \
    GloveAcquisitor/DataGloveReceiver/DataGloveReceiver_Network.cpp \
    GloveAcquisitor/DataGloveReceiver/DataGloveReceiver_Serialization.cpp \
    GloveAcquisitor/DataGloveSender/DataGloveSender_Network.cpp \
    GloveAcquisitor/DataGloveSender/DataGloveSender_Serialization.cpp \
    GloveAcquisitor/CoordinateConverter/CoordinateConverter.cpp
    ik.cpp

include( ../examples.pri )
