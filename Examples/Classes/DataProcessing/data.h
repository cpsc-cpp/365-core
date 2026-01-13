#ifndef DATA_H
#define DATA_H

#include <cstdlib>
#include <vector>
#include <iostream>

class DataSet {
public:
    
    virtual size_t getSize() const = 0; 

    virtual double &operator[](int i) = 0; 
    virtual const double &operator[](int i) const = 0;

    virtual ~DataSet() = default;
};

class VectorDataSet : public DataSet {
    std::vector<double> data;
    double outside = 0.0;
    double step = 1.0;
public:
    VectorDataSet( size_t size, double init = 0.0) : data(size, init) {}

    VectorDataSet( size_t size, double min, double max ) 
        : data(size), step{ (max - min) / (size-1) } {
            for(size_t i = 0; i < data.size(); i++) {
                data[i] = min + i*step;
            }
        }
    
        double &operator[](int i) override {
            if( i < 0 || i >= data.size() )
                return outside;
            return data[i];
        } 
        
        const double &operator[](int i) const override {
            if( i < 0 || i >= data.size() )
                return outside;
            return data[i];
        }

        size_t getSize() const override { return data.size(); }
        
        friend std::ostream& operator<<(std::ostream& out, const VectorDataSet& ds ) {
            out << "[";
            for(size_t i = 0; i < ds.data.size(); i++ ) {
                out << ds.data[i] << " ";
            }
            out << "]";
            return out;
        }
};


#endif
