// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// File        : config.h
// Description : Configuration of @PROJECT_NAME@
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#ifndef _CONFIG_H_
#define _CONFIG_H_

#define MAX_ALLOWED_ENTRIES @MAX_ALLOWED_ENTRIES@
#define CODE_SIZE @CODE_SIZE@
#define PRODUCT_ID_SIZE @PRODUCT_ID_SIZE@
#define VENDOR_NAME_SIZE @VENDOR_NAME_SIZE@

#define INC_INDEX(i,l) do { (i)=(i)-(l)*(l)+(++l)*(l); } while(0)
#define ALIGN(i) (i)

#endif /* _CONFIG_H_ */
