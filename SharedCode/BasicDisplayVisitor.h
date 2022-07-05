/* BasicDisplayVisitor.h: This file contains the declaration of the BasicDisplayVisitor class, which inherits from the 
* AbstractFileVisitor interface.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFileVisitor.h"
class BasicDisplayVisitor : public  AbstractFileVisitor {
	virtual void visit_TextFile(TextFile*);
	virtual void visit_ImageFile(ImageFile*);
};