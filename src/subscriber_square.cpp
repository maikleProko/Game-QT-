#include "subscriber_square.h"
#include "Square.h"
#include "openlog.h"
#include "libs.h"

subscriber_square::subscriber_square()
{

}

subscriber_square::~subscriber_square()
{

}

void subscriber_square::upfile(publisher *My_publisher)
{

    OpenLog::My_OpenLog()->my_file << *(dynamic_cast<Square*>(My_publisher));

}
