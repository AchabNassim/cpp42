#include "inc/Bureaucrat.hpp"
#include "inc/Form.hpp"
#include <exception>

int main() {
    Bureaucrat boss("Laarbi", 1);
    Form form("new Law", 2, 2);
    boss.signForm(form);
    return (0);
}