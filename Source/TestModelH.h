#ifndef TEST_MODEL_CORNEL_BOX_H
#define TEST_MODEL_CORNEL_BOX_H

// Defines a simple test model: The Cornel Box

#include <glm/glm.hpp>
#include <vector>

// Used to describe a triangular surface:
class Triangle
{
    public:
        glm::vec4 v0;
        glm::vec4 v1;
        glm::vec4 v2;
        glm::vec4 normal;
        glm::vec3 color;
        glm::vec3 gloss;

        Triangle( glm::vec4 v0, glm::vec4 v1, glm::vec4 v2, glm::vec3 color, glm::vec3 gloss)
            : v0(v0), v1(v1), v2(v2), color(color), gloss(gloss)
        {
            ComputeNormal();
        }

        void ComputeNormal()
        {
            glm::vec3 e1 = glm::vec3(v1.x-v0.x,v1.y-v0.y,v1.z-v0.z);
            glm::vec3 e2 = glm::vec3(v2.x-v0.x,v2.y-v0.y,v2.z-v0.z);
            glm::vec3 normal3 = glm::normalize( glm::cross( e2, e1 ) );
            normal.x = normal3.x;
            normal.y = normal3.y;
            normal.z = normal3.z;
            normal.w = 1.0;
        }
};

// Loads the Cornell Box. It is scaled to fill the volume:
// -1 <= x <= +1
// -1 <= y <= +1
// -1 <= z <= +1
void LoadTestModel( std::vector<Triangle>& triangles )
{
    using glm::vec3;
    using glm::vec4;

    // Defines colors:
    vec3 red(    0.75f, 0.15f, 0.15f );
    vec3 yellow( 0.75f, 0.75f, 0.15f );
    vec3 green(  0.15f, 0.75f, 0.15f );
    vec3 cyan(   0.15f, 0.75f, 0.75f );
    vec3 blue(   0.15f, 0.15f, 0.75f );
    vec3 purple( 0.75f, 0.15f, 0.75f );
    vec3 white(  0.75f, 0.75f, 0.75f );

    vec3 lowGloss(0.7, 0.7, 0.7);
    vec3 normalGloss(1, 1, 1);
    vec3 someGloss(1.2, 1.2, 1.2);
    vec3 moreGloss(1.5, 1.5, 1.5);
    vec3 highGloss(2, 2, 2);

    triangles.clear();
    triangles.reserve( 5*2*3 );

    // ---------------------------------------------------------------------------
    // Room

    float L = 555;			// Length of Cornell Box side.

    vec4 A(L,0,0,1);
    vec4 B(0,0,0,1);
    vec4 C(L,0,L,1);
    vec4 D(0,0,L,1);

    vec4 E(L,L,0,1);
    vec4 F(0,L,0,1);
    vec4 G(L,L,L,1);
    vec4 H(0,L,L,1);

    // Floor:
    triangles.push_back( Triangle( C, B, A, green , someGloss) );
    triangles.push_back( Triangle( C, D, B, green , someGloss) );

    // Left wall
    triangles.push_back( Triangle( A, E, C, purple, highGloss ) );
    triangles.push_back( Triangle( C, E, G, purple, highGloss ) );

    // Right wall
    triangles.push_back( Triangle( F, B, D, yellow, lowGloss ) );
    triangles.push_back( Triangle( H, F, D, yellow, lowGloss ) );

    // Ceiling
    triangles.push_back( Triangle( E, F, G, cyan , normalGloss) );
    triangles.push_back( Triangle( F, H, G, cyan , normalGloss) );

    // Back wall
    triangles.push_back( Triangle( G, D, C, white, someGloss ) );
    triangles.push_back( Triangle( G, H, D, white, someGloss ) );

    // ---------------------------------------------------------------------------
    // Short block

    A = vec4(290,0,114,1);
    B = vec4(130,0, 65,1);
    C = vec4(240,0,272,1);
    D = vec4( 82,0,225,1);

    E = vec4(290,165,114,1);
    F = vec4(130,165, 65,1);
    G = vec4(240,165,272,1);
    H = vec4( 82,165,225,1);

    // Front
    triangles.push_back( Triangle(E,B,A,red, someGloss) );
    triangles.push_back( Triangle(E,F,B,red, someGloss) );

    // Front
    triangles.push_back( Triangle(F,D,B,red, someGloss) );
    triangles.push_back( Triangle(F,H,D,red, someGloss) );

    // BACK
    triangles.push_back( Triangle(H,C,D,red, someGloss) );
    triangles.push_back( Triangle(H,G,C,red, someGloss) );

    // LEFT
    triangles.push_back( Triangle(G,E,C,red, someGloss) );
    triangles.push_back( Triangle(E,A,C,red, someGloss) );

    // TOP
    triangles.push_back( Triangle(G,F,E,red, someGloss) );
    triangles.push_back( Triangle(G,H,F,red, someGloss) );

    // ---------------------------------------------------------------------------
    // Tall block

    A = vec4(423,0,247,1);
    B = vec4(265,0,296,1);
    C = vec4(472,0,406,1);
    D = vec4(314,0,456,1);

    E = vec4(423,330,247,1);
    F = vec4(265,330,296,1);
    G = vec4(472,330,406,1);
    H = vec4(314,330,456,1);

    // Front
    triangles.push_back( Triangle(E,B,A,blue, highGloss) );
    triangles.push_back( Triangle(E,F,B,blue, highGloss) );

    // Front
    triangles.push_back( Triangle(F,D,B,blue, highGloss) );
    triangles.push_back( Triangle(F,H,D,blue, highGloss) );

    // BACK
    triangles.push_back( Triangle(H,C,D,blue, highGloss) );
    triangles.push_back( Triangle(H,G,C,blue, highGloss) );

    // LEFT
    triangles.push_back( Triangle(G,E,C,blue, highGloss) );
    triangles.push_back( Triangle(E,A,C,blue, highGloss) );

    // TOP
    triangles.push_back( Triangle(G,F,E,blue, highGloss) );
    triangles.push_back( Triangle(G,H,F,blue, highGloss) );


    // ----------------------------------------------
    // Scale to the volume [-1,1]^3

    for( size_t i=0; i<triangles.size(); ++i )
    {
        triangles[i].v0 *= 2/L;
        triangles[i].v1 *= 2/L;
        triangles[i].v2 *= 2/L;

        triangles[i].v0 -= vec4(1,1,1,1);
        triangles[i].v1 -= vec4(1,1,1,1);
        triangles[i].v2 -= vec4(1,1,1,1);

        triangles[i].v0.x *= -1;
        triangles[i].v1.x *= -1;
        triangles[i].v2.x *= -1;

        triangles[i].v0.y *= -1;
        triangles[i].v1.y *= -1;
        triangles[i].v2.y *= -1;

        triangles[i].v0.w = 1.0;
        triangles[i].v1.w = 1.0;
        triangles[i].v2.w = 1.0;

        triangles[i].ComputeNormal();
    }
}

#endif
