/*MetaDisplayVisitor.h: This file contains the declaration for the MetaDisplayVisitor class, which inherits from AbstractFileVisitor
* and is a visitor that helps print out a file's metadata. 
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
#include "AbstractFileVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"
class MetadataDisplayVisitor: public AbstractFileVisitor{
public:
	virtual void visit_TextFile(TextFile*);
	virtual void visit_ImageFile(ImageFile*);
};
