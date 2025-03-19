template <typename T> requires std::floating_point<T>
class complex_number
{
	T real_part, im_part;
	
public:

/* default constructor, followed by the two user constructors seen in the lecture */

	complex_number()
		: real_part(0), im_part(0)
	{}
	
	explicit complex_number(T n)
		:real_part(n),im_part(0)
	{}
	
	complex_number (T n, T m)
		: real_part(n), im_part(m)
	{}
	/* in the following lines, I define the method rp that gives 
	the real part of a complex number */
	T rp(void) const {
		return real_part;
	}
	
	/* in the following lines, I define the method ip that gives 
	the imaginary part of a complex number */
	T ip(void) const{
		return im_part;
	}
	
	/* in the following lines, I define the method conjugate */
	complex_number<T> conjugate(void) {
		return complex_number<T>(real_part,-im_part);
	}
	
	/* now, we can define the operator += for complex numbers */
	 complex_number& operator+=(const complex_number& other) {
        T a = real_part;
        T b = im_part;
        T c = other.real_part;
        T d = other.im_part;
        real_part = a+c;
        im_part = b+d;
        return *this;
	}
	
	/* definition of + operator between complex numbers, using the += defined above */
	
	complex_number operator+(const complex_number& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
	
	/* now we define the *= and * operators between complex numbers, 
	in a similar way to the sum operators */
	complex_number& operator*=(const complex_number& other) {
        T a = real_part;
        T b = im_part;
        T c = other.real_part;
        T d = other.im_part;
        real_part = a*c-b*d;
        im_part = a*d+b*c;
        return *this;
	}
	
	complex_number operator*(const complex_number& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
	
	/* Now, I define the +=, +, *= and * operators for a complex number 
	and a type T on the right: */
	
	   complex_number& operator+=(const T& other) {
        real_part += other;
        return *this;
	}
	
	complex_number operator+(const T& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
	
	   complex_number& operator*=(const T& other) {
        real_part *= other;
		im_part *= other;
        return *this;
	}
	
	complex_number operator*(const T& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
};

/* the following two operators are defined outside of the class "complex_number"
and are needed to compute the sum and product of a type T on the left and a 
complex number on the right */

template<typename T> requires std::floating_point<T>
complex_number<T>
operator+(const T& i, const complex_number<T>& r)
{
    return r + i;
}

template<typename T> requires std::floating_point<T>
complex_number<T>
operator*(const T& i, const complex_number<T>& r)
{
    return r * i;
}

/* overload of the << operator, to print complex numbers */

template<typename T> requires std::floating_point<T>
std::ostream&
operator<<(std::ostream& os, const complex_number<T>& r) {
    if (r.ip() != 0)
		if(r.ip()>0)
			if(r.ip()!=1)
				os << r.rp() << "+" << r.ip()<< "i";
			else
				os << r.rp() << "+i";
		else
			if(r.ip()!=-1)
				os << r.rp() << "" <<r.ip()<<"i";
			else
				os << r.rp() << "-i";
    else
        os << r.rp();

    return os;
}