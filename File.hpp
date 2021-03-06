// File.hpp
// 
// by Leland Pierce, Feb 18, 2017
//
//-------------------------------------
#ifndef FILE_HPP_
#define FILE_HPP_


#include <string>

#include "H5Cpp.h"

#include "Image.hpp"
#include "attributes.hpp"

namespace GeoStar {



/** \brief File -- Implementation of file operations for HDF5-based GeoStar files.


This class is used as the standard interface for file operations 
 that are used for storing and processing of data in GeoStar using the HDF5 implementation.
In particular, first, data is imported into GeoStar from data provided by a remote sensing data
processing facility, or the output from another data processing system.
This data is stored in the GeoStar file format.

\see File, Image, Raster

\par Usage Overview
The File class is meant to be used when dealing with GeoStar files. 
Other classes are used to deal with external files in other formats.
This class provides methods for creating and deleting files, as well as opening and closing them.

Creation of a file requires a file name.

Deleting a file is only possible if it is not "open".

Opening a file requires it to already exist, and merely requires the filename, and an access string.

Closing a file is a major issue, since all the other open objects within the file must be closed as well.
This class currently does not implement this function.

This class also enables one to create, open, and close images within this file.

\par Details
This class also has two functions to deal with the object-type metadata, reading and writing.
This metadata identifies this file as a GeoStar file.

The class keeps track of the filename, in case that is needed.

The function create_image and open_image merely call the appropriate constructors in the Image class.

There are 3 functions to deal with HDF5 groups in the file: checking on existence, creating, and opening.

*/	

  class File {
    
  private:
    std::string filename;
    std::string filetype;

  public:
    H5::H5File *fileobj;

  /** \brief File constructor allows one to create a new GeoStar file or open an existing one.

   The File constructor is used to make a new file, or open an existing file in the HDF5 GeoStar file format.
   The new file is created empty, except for the needed metadata to define it as a GeoStar file.
   In both cases, the file is also opened, and a valid File object is returned.

   \see open, close

   \param[in] name
       This is a string, set by the user, that holds the desired name of the new file.

   \param[in] acess
       This is a string, set by the user, that should be set to one of 2 strings:
            "new": create a new file, existence is an error
            "existing": open an existing file, non-existence is an error

   \returns
       A valid File object on success.

   \par Exceptions
       Exceptions that may be raised by this method:
       FileAccessException 
       FileExistsException 
       FileDoesNotExistException 

   \par Example
       Let's say a user wants to create a file named "sirc_raco":
       \code
       #include "geostar.hpp"
       #include <string>
       using namespace std;
       int main() 
       {
           GeoStar::File *file;
	   try {
               file = new GeoStar::File("sirc_raco","new");
	   }//end-try 
	   catch (...) {
	       cerr << "GeoStar::File creation failure"<<endl;
	   }//end-catch

       }//end-main
       \endcode

    \par Details
       The HDF5 file attribute named "object_type" is created for a new file and filled 
       with value "geostar::hdf5".
       For existing files, this attribute must exist and have this value, or it is not 
       a GeoStar file, and an exception is thrown.
  
  */
    File(const std::string &name, const std::string &access);


  /** \brief File::write_object_type allows one to change the value of the attribute string 
      named "object_type" that is attached to this file.

   File::write_object_type allows one to change the value of the attribute string 
      named "object_type" that is attached to this file.

   \see  File

   \param[in] name
       This is a string, set by the user, that holds the desired value for the attribute string.

   \returns
       nothing.

   \par Exceptions
       Exceptions that may be raised by this method:
       AttributeErrorException

   \par Example
       This is not for use by most users. An admin can use this to write a coded string
       to this attribute. It is meant for identifying this HDF5 file as a GeoStar file, 
       using the string "geostar::hdf5", as in this example:
       \code
       #include "geostar.hpp"
       #include <string>
       using namespace std;
       int main() 
       {
           GeoStar::File *file;
	   try {
               file = new GeoStar::File("sirc_raco","new");
	   }//end-try 
	   catch (...) {
	       cerr << "GeoStar::File creation failure"<<endl;
	   }//end-catch

           file->write_object_type("geostar::hdf5");

       }//end-main
       \endcode

    \par Details
       Implementation in attributes.cpp for any object type. 
       The implementation in this class makes it easier to use in the File context.
  
  */
    inline void write_object_type(const std::string &value) {
      GeoStar::write_object_type((H5::H5Location *)fileobj,value);
    }


  /** \brief File::read_object_type allows one to read the string value of the attribute
      named "object_type" that is attached to this file.

   File::read_object_type allows one to read the string value of the attribute
      named "object_type" that is attached to this file.

   \see  File

   \param[in] name
       This is a string, set by the user, that holds the desired value for the attribute string.

   \returns
       the value of the attribute as a string.

   \par Exceptions
       Exceptions that may be raised by this method:
       AttributeErrorException

   \par Example
       This is not for use by most users. An admin can use this to read the value of
       this attribute. It is meant for identifying this HDF5 file as a GeoStar file, 
       using the string "geostar::hdf5", as in this example:
       \code
       #include "geostar.hpp"
       #include <string>
       using namespace std;
       int main() 
       {
           GeoStar::File *file;
	   try {
               file = new GeoStar::File("sirc_raco","new");
	   }//end-try 
	   catch (...) {
	       cerr << "GeoStar::File creation failure"<<endl;
	   }//end-catch

           if(file->read_object_type("geostar::hdf5") != "geostar:hdf5" ) {
	       cerr << "GeoStar::read_object_type: this is not a geostar file"<<endl;
           }// endif

       }//end-main
       \endcode

    \par Details
       Implementation in attributes.cpp for any object type. 
       The implementation in this class makes it easier to use in the File context.
  
  */
    inline std::string read_object_type() const {
      return GeoStar::read_object_type((H5::H5Location *)fileobj);
    }

  /** \brief File destructor allows one to delete a File object from memory.

   The File destructor is automatically called to clean up memory used by the File object.
   There is a single pointer to the HDF5 file object that must be deleted.

   \see open, close

   \returns
       Nothing.

   \par Exceptions
       Exceptions that may be raised by this method:
       None.

   \par Example
       Let's say a user wants to create a file named "sirc_raco":
       \code
       #include "geostar.hpp"
       #include <string>
       using namespace std;
       int main() 
       {
           GeoStar::File *file;
	   try {
               file = new GeoStar::File("sirc_raco","new");
	   }//end-try 
	   catch (...) {
	       cerr << "GeoStar::File creation failure"<<endl;
	   }//end-catch

       }//end-main
       \endcode

       Before main ends, the c++ run-time system automatically destroys the file variable 
       using the File object destructor.

  */
    inline ~File() {
      delete fileobj;
    }


  /** \brief File::create_image allows one to create a new GeoStar image.

   File::create_image is used to make a new image in a GeoStar File.
   The new image is created empty, except for the needed metadata to define it as a GeoStar image.
   On success, a valid Image object is returned.

   \see  open_image

   \param[in] name
       This is a string, set by the user, that holds the desired name of the new image.

   \returns
       A valid Image object on success.

   \par Exceptions
       Exceptions that may be raised by this method:
       None

   \par Example
       Let's say a user wants to create an image named "dt102.41":
       \code
       #include "geostar.hpp"
       #include <string>
       using namespace std;
       int main() 
       {
           GeoStar::File *file;
	   try {
               file = new GeoStar::File("sirc_raco","new");
	   }//end-try 
	   catch (...) {
	       cerr << "GeoStar::File creation failure"<<endl;
	   }//end-catch

           GeoStar::Image *img;
	   try {
               *img = file->create_image("dt102.41");
	   }//end-try 
	   catch (...) {
	       cerr << "GeoStar::Image creation failure"<<endl;
	   }//end-catch


       }//end-main
       \endcode

    \par Details
       The HDF5 image attribute named "object_type" is created for the new image and filled 
       with value "geostar::image".
       For existing images, this attribute must exist and have this value, or it is not 
       a GeoStar image, and an exception is thrown.
  
  */
    inline Image *create_image(const std::string &name) {
      return new Image(this,name);
    }


  /** \brief File::open_image allows one to open an existing GeoStar image.

   File::open_image is used to open an existing image in a GeoStar File.
   On success, a valid Image object is returned.

   \see  open_image

   \param[in] name
       This is a string, set by the user, that holds the name of the existing image.

   \returns
       A valid Image object on success.

   \par Exceptions
       Exceptions that may be raised by this method:
       ImageOpenErrorException

   \par Example
       Let's say a user wants to open an image named "dt102.41":
       \code
       #include "geostar.hpp"
       #include <string>
       using namespace std;
       int main() 
       {
           GeoStar::File *file;
	   try {
               file = new GeoStar::File("sirc_raco","new");
	   }//end-try 
	   catch (...) {
	       cerr << "GeoStar::File creation failure"<<endl;
	   }//end-catch

           GeoStar::Image *img;
	   try {
               *img = file->open_image("dt102.41");
	   }//end-try 
	   catch (...) {
	       cerr << "GeoStar::Image open failure"<<endl;
	   }//end-catch


       }//end-main
       \endcode

    \par Details
       The HDF5 image attribute named "object_type" must exist for the existing image and 
       must have the value "geostar::image".
       Otherwise, it is not a GeoStar image, and an exception is thrown.
  
  */
    inline Image *open_image(const std::string &name) {
      return new Image(this,name);
    }

  /** \brief File::groupExists returns true if the named group exists, false otherwise.

   File::groupExists is used to check on the existence of a group, before trying to create
   a new one. This is to avoid name collisions. Returns true of the group exists, false otherwise.

   \see  open_image

   \param[in] name
       This is a string, set by the user, that holds the name of the group.

   \returns
       true if group exists,
       false if group does not exist.

   \par Exceptions
       Exceptions that may be raised by this method:
       none

   \par Example
       This function is not for use by most users. An admin user could use this
       function to check for the existence of a group, and then either create it or open it.
       In this example, we are checking for a group named "dt86.2".
       \code
       #include "geostar.hpp"
       #include <string>
       using namespace std;
       int main() 
       {
           GeoStar::File *file;
	   try {
               file = new GeoStar::File("sirc_raco","new");
	   }//end-try 
	   catch (...) {
	       cerr << "GeoStar::File creation failure"<<endl;
	   }//end-catch

           if(file->groupExists("dt86.2")){
           // open the group...
           } else {
           // create the group.
           } //endif

       }//end-main
       \endcode

    \par Details
       This routine is not for the use of most users.
       This rouine merely tries to open the group, and on success it closes the group and returns true.
       On failure, it returns false.
  */
    bool groupExists(const std::string &name);


  /** \brief File::createGroup creates the named group and returns it.

   File::createGroup  creates the named group and returns it.
   
   \see  create_image

   \param[in] name
       This is a string, set by the user, that holds the name of the group.

   \returns
       The group on success.

   \par Exceptions
       Exceptions that may be raised by this method:
       none

   \par Example
       This function is not for use by most users. 
       An admin user should first check for the existence of a group, 
       and then create it if it does not yet exist.
       In this example, we are opening a group named "dt86.2".
       \code
       #include "geostar.hpp"
       #include <string>
       using namespace std;
       int main() 
       {
           GeoStar::File *file;
	   try {
               file = new GeoStar::File("sirc_raco","new");
	   }//end-try 
	   catch (...) {
	       cerr << "GeoStar::File creation failure"<<endl;
	   }//end-catch

           H5::Group *imageobj;
           if(file->groupExists("dt86.2")){
	       cerr << "GeoStar::createGroup: group already exists"<<endl;
           } else {
              // create the group
              imageobj = new H5::Group(  file->createGroup("dt86.2"));
           } //endif

       }//end-main
       \endcode

    \par Details
       This routine is not for the use of most users.
       It is basically a stub that calls the HDF5 function of the same name.
  */
    inline H5::Group createGroup(const std::string &name) {
      return fileobj->createGroup(name);
    }

  /** \brief File::openGroup opens the named group and returns it.

   File::openGroup  opens the named group and returns it.
   
   \see  open_image

   \param[in] name
       This is a string, set by the user, that holds the name of the group.

   \returns
       The group on success.

   \par Exceptions
       Exceptions that may be raised by this method:
       none

   \par Example
       This function is not for use by most users. 
       An admin user should first check for the existence of a group, 
       and then open it.
       In this example, we are opening a group named "dt86.2".
       \code
       #include "geostar.hpp"
       #include <string>
       using namespace std;
       int main() 
       {
           GeoStar::File *file;
	   try {
               file = new GeoStar::File("sirc_raco","new");
	   }//end-try 
	   catch (...) {
	       cerr << "GeoStar::File creation failure"<<endl;
	   }//end-catch

           H5::Group *imageobj;
           if(file->groupExists("dt86.2")){
              // open the group...
              imageobj = new H5::Group(  file->openGroup("dt86.2"));
           } else {
	       cerr << "GeoStar::openGroup: group does does not exist"<<endl;
           } //endif

       }//end-main
       \endcode

    \par Details
       This routine is not for the use of most users.
       It is basically a stub that calls the HDF5 function of the same name.
  */
    inline H5::Group openGroup(const std::string &name) {
      return fileobj->openGroup(name);
    }

  }; // end class: File
  
}// end namespace GeoStar

#endif // FILE_HPP_

