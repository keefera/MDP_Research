#ifndef EXCEPTIONS_HPP_
#define EXCEPTIONS_HPP_

#include <exception>
using namespace std;


namespace GeoStar {

  class SliceSizeException: public exception
  {
    virtual const char* what() const throw()
    {
      return "SliceSizeError";
    }
  };

  class DataTypeException: public exception
  {
    virtual const char* what() const throw()
    {
      return "DataTypeError";
    }
  };


    class FileExistsException: public exception
    {
        virtual const char* what() const throw()
            {
                return "FileExists";
            }
    };
    class FileAccessException: public exception
    {
        virtual const char* what() const throw()
            {
                return "FileAccessError";
            }
    };
    class FileDoesNotExistException: public exception
    {
        virtual const char* what() const throw()
            {
                return "FileDoesNotExist";
            }
    };
    class FileCreationErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "FileCreationError";
            }
    };
    class FileOpenErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "FileOpenError";
            }
    };
    class FileDestroyErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "FileDestroyError";
            }
    };


    class ImageExistsException: public exception
    {
        virtual const char* what() const throw()
            {
                return "ImageExists";
            }
    };
    class ImageDoesNotExistException: public exception
    {
        virtual const char* what() const throw()
            {
                return "ImageDoesNotExist";
            }
    };
    class ImageCreationErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "ImageCreationError";
            }
    };
    class ImageOpenErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "ImageOpenError";
            }
    };
    class ImageDestroyErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "ImageDestroyError";
            }
    };






  // exceptions:
  //struct FileExists{};
  //struct FileDoesNotExist{};
  //struct FileCreationError{};
  //struct FileOpenError{};
  //struct FileDestroyError{};

  //struct ImageExists{};
  //struct ImageDoesNotExist{};
  //struct ImageCreationError{};
  //struct ImageOpenError{};
  //struct ImageDestroyError{};

    class RasterExistsException: public exception
    {
        virtual const char* what() const throw()
            {
                return "RasterExists";
            }
    };
    class RasterDoesNotExistException: public exception
    {
        virtual const char* what() const throw()
            {
                return "RasterDoesNotExist";
            }
    };
    class RasterCreationErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "RasterCreationError";
            }
    };

    class RasterReadErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "RasterReadError";
            }
    };
    class RasterWriteErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "RasterWriteError";
            }
    };


    class RasterOpenErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "RasterOpenError";
            }
    };
    class RasterDestroyErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "RasterDestroyError";
            }
    };
    class RasterSizeErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "RasterSizeError";
            }
    };


    //struct RasterExists{};
    //struct RasterDoesNotExist{};
    //struct RasterCreationError{};
    //struct RasterOpenError{};
    //struct RasterDestroyError{};

    class MetadatExistsException: public exception
    {
        virtual const char* what() const throw()
            {
                return "MetadataExists";
            }
    };
    class MetadataDoesNotExistException: public exception
    {
        virtual const char* what() const throw()
            {
                return "MetadataDoesNotExist";
            }
    };
    class MetadatCreationErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "MetadataCreationError";
            }
    };
    class MetadatOpenErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "MetadatapenError";
            }
    };
    class MetadatDestroyErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "MetadataDestroyError";
            }
    };

    //struct MetadataExists{};
    //struct MetadataDoesNotExist{};
    //struct MetadataCreationError{};
    //struct MetadataOpenError{};
    //struct MetadataDestroyError{};

    class AttributeExistsException: public exception
    {
        virtual const char* what() const throw()
            {
                return "AttributeExists";
            }
    };
    class AttributeDoesNotExistException: public exception
    {
        virtual const char* what() const throw()
            {
                return "AttributeDoesNotExist";
            }
    };
    class InvalidAttributeFormatException: public exception
    {
        virtual const char* what() const throw()
            {
                return "InvalidAttributeFormat";
            }
    };
    class AttributeErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "AttributeError";
            }
    };

    //struct AttributeExists{};
    //struct AttributeDoesNotExist{};
    //struct InvalidAttributeFormat{};
    //struct AttributeError{};

    class DirectoryExistsException: public exception
    {
        virtual const char* what() const throw()
            {
                return "DirectoryExists";
            }
    };
    class DirectoryDoesNotExistException: public exception
    {
        virtual const char* what() const throw()
            {
                return "DirectoryDoesNotExist";
            }
    };
    class DirectoryCreationErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "DirectoryCreationError";
            }
    };
   class BitException: public exception
    {
      virtual const char* what() const throw()
          {
              return "BitValueError";
          }
    };
    class PartitionException: public exception
    {
      virtual const char* what() const throw()
          {
              return "PartitionError";
          }
    };
    class DirectoryDestroyErrorException: public exception
    {
        virtual const char* what() const throw()
            {
                return "DirectoryDestroyError";
            }
    };
    class ProbabilityException: public exception
    {
      virtual const char* what() const throw()
          {
              return "ProbabilityParameterError";
          }
    };
    class IntegerParameterException: public exception
    {
      virtual const char* what() const throw()
          {
              return "Integer Parameter Invalid";
          }
    };
    class MapSizeException: public exception
    {
      virtual const char* what() const throw()
          {
              return "Invalid map size";
          }
    };
    class PNGSizeException: public exception
    {
      virtual const char* what() const throw()
          {
              return "Invalid PNG size";
          }
    };

    //struct DirectoryExists{};
    //struct DirectoryDoesNotExist{};
    //struct DirectoryCreationError{};
    //struct DirectoryDestroyError{};

    class NotGeoSciFileException: public exception
    {
        virtual const char* what() const throw()
            {
                return "NotGeoSciFile";
            }
    };
    
    class NotGeoSciImageException: public exception
    {
        virtual const char* what() const throw()
            {
                return "NotGeoSciImage";
            }
    };
    class NotGeoSciRasterException: public exception
    {
        virtual const char* what() const throw()
            {
                return "NotGeoSciRaster";
            }
    };

    // Raster arithmetic
    class DivideByZeroException: public exception
    {
      virtual const char* what() const throw()
          {
              return "DivideByZeroError";
          }
    };

	class RadiusSizeException: public exception
    {
      virtual const char* what() const throw()
          {
              return "RadiusSizeError";
          }
    };




    //struct NotGeoSciFile{};
    //struct NotGeoSciImage{};
    //struct NotGeoSciRaster{};

}// end namespace GeoStar


#endif
//end EXCEPTIONS_HPP_

