#ifndef __NONCOPYABLE__
#define __NONCOPYABLE__


/// \author Rene Keijzer<rene.keijzer@student.hu.nl>
/// \class NonCopyable
/// \brief Simple non copyable class inspired Boost::nonCopyable
class NonCopyable {
protected:
	NonCopyable() = default;
	~NonCopyable() = default;

	NonCopyable(const NonCopyable&) = delete;
	NonCopyable& operator = (const NonCopyable &) = delete;
};
#endif