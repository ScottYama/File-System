/*AbstractFileVisitor.h: This file contains the declaration of the file visitor interface.
* Authors: Jeremy Ouyang, Scott Yamomoto
*/
#pragma once
class TextFile;
class ImageFile;
class AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile*) = 0;
	virtual void visit_ImageFile(ImageFile*) = 0;
};