/*
 *  OwnedCFRef.h
 *  SoundFXMachine
 *
 *  Created by James Russell McClellan on 4/3/11.

 Permission is hereby granted, free of charge, to any person or organization
 obtaining a copy of the software and accompanying documentation covered by
 this license (the "Software") to use, reproduce, display, distribute,
 execute, and transmit the Software, and to prepare derivative works of the
 Software, and to permit third-parties to whom the Software is furnished to
 do so.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.
 
 *
 */

#ifndef OwnedCFRef_h
#define OwnedCFRef_h

#define QUOTEME_(x) #x
#define QUOTEME(x) QUOTEME_(x)

template<typename cftype>
class OwnedCFRef
{
public:
    OwnedCFRef(cftype obj) : fObj(obj) {}
    ~OwnedCFRef() {if(fObj) CFRelease(fObj);}
    cftype get() {return fObj;}
    
private:
    OwnedCFRef(const OwnedCFRef<cftype>&);
    OwnedCFRef& operator = (const OwnedCFRef<cftype>&);
    
    cftype fObj;
};

template<class T>
class auto_array
{
public:
    auto_array(T* t_array = 0) : array(t_array) {}
    T* get() {return array;}
    void reset(T* new_array = 0)
    {
        if(array)
            delete [] array;
        
        array = new_array;
    }
    
    ~auto_array()
    {
        reset();
    }  
    
    auto_array(const auto_array<T>& other)
    {
        array = other.array;
        other.reset();
    }
    
    auto_array<T>& operator= (const auto_array<T>& other)
    {
        array = other.array;
        other.reset();
        return *this;
    }
private:
    T* array;
};

#endif