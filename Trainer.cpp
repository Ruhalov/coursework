#include "Trainer.h"

void Trainer::initScoreFont()
{
    if (!scoreFont.loadFromFile("fonts/score-font.otf"))
    {
        throw ("Could not load font file: \"score-font.otf\"");
    }
}
