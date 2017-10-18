AC_INIT(mips32-npc, 1.0)

# Determine a C++ compiler to use
AC_PROG_CXX

AC_LANG_PUSH([C++])
CXXFLAGS="$CXXFLAGS -std=gnu++0x"
AC_LANG_POP

# Chisel/Scala sources
AC_ARG_WITH(chisel, [  --with-chisel           path to chisel sources])

AS_IF([test "x$with_chisel" != "x"],
      [AC_SUBST(chisel_version, latest.SNAPSHOT)],
      [AC_SUBST(chisel_version, latest.release)])

AC_SUBST(chiseldir, $with_chisel)

AC_OUTPUT(
    prefix.mk
    Makefile
    project/plugins.sbt
    project/build.properties
    project/build.scala
)
