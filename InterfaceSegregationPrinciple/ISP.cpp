// Interface segregation Principle
// no client should be forced to depend on methods it does not use

#include <iostream>
#include <vector>

struct Document;
struct IMachine
{
    virtual void print(std::vector<Document *> docs) = 0;
    virtual void scan(std::vector<Document *> docs) = 0;
    virtual void fax(std::vector<Document *> docs) = 0;
};

//each time you are changing smth e.g. print, you need to recompile two others as well
//maybe user would be happy with only one of the methods, and having an access to other may lead to wrong calls
//user is forced to implement too much
//conclusion that is a bad solution
struct MFP : IMachine
{
    void print(std::vector<Document *> docs) override;
    void scan(std::vector<Document *> docs) override;
    void fax(std::vector<Document *> docs) override;
};

//better to have separate interfaces
struct IPrinter
{
    virtual void print(std::vector<Document *> docs) = 0;
};
struct IScanner
{
    virtual void scan(std::vector<Document *> docs) = 0;
};
struct IFax
{
    virtual void fax(std::vector<Document *> docs) = 0;
};

struct Printer : public IPrinter
{
    virtual void print(std::vector<Document *> docs) override;
};
struct Scanner : public IScanner
{
    virtual void scan(std::vector<Document *> docs) override;
};
struct Fax : public IFax
{
    virtual void fax(std::vector<Document *> docs) override;
};

//bad solution, better to have again an abstract class
struct PrinterScanner : public IScanner, IPrinter
{
    virtual void scan(std::vector<Document *> docs) override;
    virtual void print(std::vector<Document *> docs) override;
};

struct IMFP : public IScanner, IPrinter, IFax
{
};


//That is a decorator
struct MyMFP : public IMFP
{
    IPrinter &printer;
    IScanner &scanner;
    IFax &faxer;
    //by creating new types of e.g. from IPrinter we can inject new types in this consructor.
    //e.g. color printer, bw printer, matrix printer
    MyMFP(IPrinter &printer, IScanner &scanner, IFax &fax)
        : printer{printer},
          scanner{scanner},
          faxer{fax}
    {
    }

    void print(std::vector<Document *> docs) override
    {
        printer.print(docs);
    };
    void scan(std::vector<Document *> docs) override
    {
        scanner.scan(docs);
    };
    void fax(std::vector<Document *> docs) override
    {
        faxer.fax(docs);
    };
};

int main()
{
}