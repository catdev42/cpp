#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample{

    public:

    Sample(void);
    ~Sample(void);

    static int getNbinst(void);

    private:

    static int _nbinst;
};

#endif /* Sample Class */
