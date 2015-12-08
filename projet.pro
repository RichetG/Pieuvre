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
    projet.h
SOURCES  = main.cpp \
    vertex.cpp \
    normale.cpp \
    face.cpp \
    tripletface.cpp \
    texture.cpp \
    joint.cpp \
    projet.cpp

include( ../examples.pri )
