# The <code>animate()</code> function illustrated by a water particle simulation.

# When animation is activated (the Return key toggles animation), the <code>animate()</code> and
# then the <code>draw()</code> functions are called in an infinite loop.

# You can tune the frequency of your animation (default is 25Hz) using
# <code>setAnimationInterval()</code>. The frame rate will then be fixed, provided that your
# animation loop function is fast enough.

TEMPLATE = app
TARGET   = animation

HEADERS  = \
    projet.h \
    vertex.h \
    face.h \
    normale.h \
    texture.h \
    tripletface.h
SOURCES  = main.cpp \
    projet.cpp \
    vertex.cpp \
    normale.cpp \
    face.cpp \
    tripletface.cpp \
    texture.cpp

include( ../examples.pri )
