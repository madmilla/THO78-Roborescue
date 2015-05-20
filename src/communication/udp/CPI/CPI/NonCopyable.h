#ifndef __NONCOPYABLE__
#define __NONCOPYABLE__
class NonCopyable {
protected:
	NonCopyable() = default;
	~NonCopyable() = default;

	NonCopyable(const NonCopyable&) = delete;
	NonCopyable& operator = (const NonCopyable &) = delete;
};
#endif