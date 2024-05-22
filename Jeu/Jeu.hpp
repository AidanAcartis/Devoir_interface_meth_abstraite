#ifndef JEU_HPP
#define JEU_HPP

class Jeu {
public:
    virtual void start() = 0;
    virtual void restart() = 0;
    virtual void pause() = 0;
    virtual void exitJeu() = 0;
    virtual ~Jeu() {}
};

#endif // JEU_HPP
