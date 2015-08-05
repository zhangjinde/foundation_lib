/* config.h  -  Foundation library  -  Public Domain  -  2013 Mattias Jansson / Rampant Pixels
 *
 * This library provides a cross-platform foundation library in C11 providing basic support data types and
 * functions to write applications and games in a platform-independent fashion. The latest source code is
 * always available at
 *
 * https://github.com/rampantpixels/foundation_lib
 *
 * This library is put in the public domain; you can redistribute it and/or modify it without any restrictions.
 *
 */

#pragma once

/*! \file config.h
\brief Configuration repository

Simple configuration repository and configuration file parsing. Configuration value are stored
by section and key, normally indexed by hash of the section/key string. Different sections can
have the same key stored without interfering.

Values are transparently translated to the different supported types (boolean, integer, real
and string), so setting an integer value of 123 would yield a true boolean value, 123 integer
value, 123.0 real value and "123" string value.

String values are lazily evaluated and not allocated until queried. Setting an integer value
123 would not allocate memory to hold the string value "123" until the string value is actually
queried with a call to <code>config_string</code> or <code>config_string_hash</code>

Values can also be set to variables using string of format "$(section:key)" or "$(key)". If no
section is given, the currently evaluating section is used. In this mode all evaluation is lazy
and performed in the different get functions. Lookup is recursive, so a value can map to another
lazily evaluated variable config value.

A reserved section is "environment" which can be used to access the data provided by the
environment_* family of functions using the following keys:
<ul>
<li>executable_name - Current executable name
<li>executable_directory - Current executable directory
<li>executable_path - Current executable full path
<li>initial_working_directory - Initial working directory
<li>current_working_directory - Current working directory
<li>home_directory - User home directory
<li>temporary_directory - Temporary directory
<li>variable[varname] - Environment variable named "varname"
</ul>

Config format when parsing config files/streams is compatible with "standard" INI files
(see http://en.wikipedia.org/wiki/INI_file). Numbers can have the k/K or m/M suffix for
kilo or mega multipliers (4M meaning 4*1024*1024)
<pre>[section]
name = value
kil = 100k
meg = 4M
; comment
\# comment
</pre>

Config repository is not inherently thread safe, synchronization must be done by caller
in a multithreaded use case */

#include <foundation/platform.h>
#include <foundation/types.h>

/*! Get config value as boolean
\param section  Section
\param key      Key
\return         Boolean value, default to false if section:key store not set */
FOUNDATION_API bool
config_bool(hash_t section, hash_t key);

/*! Get config value as integer
\param section  Section
\param key      Key
\return         Integer value, default to 0 if section:key store not set */
FOUNDATION_API int64_t
config_int(hash_t section, hash_t key);

/*! Get config value as real
\param section  Section
\param key      Key
\return         Real value, default to 0 if section:key store not set */
FOUNDATION_API real
config_real(hash_t section, hash_t key);

/*! Get config value as hash of the string value
\param section  Section
\param key      Key
\return         Hash of string value, default to hash of an empty string if
                section:key store not set */
FOUNDATION_API hash_t
config_hash(hash_t section, hash_t key);

/*! Get config value as string
\param section  Section
\param key      Key
\return         String value, default to empty string ("") if section:key store not set */
FOUNDATION_API string_const_t
config_string(hash_t section, hash_t key);

/*! Set boolean config value. Will auto-translate to integer value 0/1, real value 0/1 and
string value "false"/"true"
\param section  Section
\param key      Key
\param value    New boolean value */
FOUNDATION_API void
config_set_bool(hash_t section, hash_t key, bool value);

/*! Set integer config value. Will auto-translate to boolean value false/true (with 0 mapping
to false and all other values mapping to true) and corresponding real and string values
(using string_from_int)
\param section  Section
\param key      Key
\param value    New integer value */
FOUNDATION_API void
config_set_int(hash_t section, hash_t key, int64_t value);

/*! Set real config value. Will auto-translate to boolean value false/true (with 0 mapping
to false and all other values mapping to true) and corresponding integer and string
values (using string_from_real)
\param section  Section
\param key      Key
\param value    New real value */
FOUNDATION_API void
config_set_real(hash_t section, hash_t key, real value);

/*! Set string config value. Will auto-translate to boolean value false/true (with "false"
and "0" mapping to false and all other values mapping to true) and corresponding integer
and real values (using string_to_int and string_to_real)
\param section  Section
\param key      Key
\param value    New string value
\param length   Length of new string value */
FOUNDATION_API void
config_set_string(hash_t section, hash_t key, const char* value, size_t length);

/*! Set constand string config value. Will auto-translate to boolean value false/true
(with "false" and "0" mapping to false and all other values mapping to true) and
corresponding integer and real values (using string_to_int and string_to_real).
Does not allocate memory but will rather store the constant string pointer, and
requires the pointer to be valid as long as the config value is stored.
\param section  Section
\param key      Key
\param value    New constant string value
\param length   Length of new string value */
FOUNDATION_API void
config_set_string_constant(hash_t section, hash_t key, const char* value, size_t length);

/*! Load config values from a file/stream, optionally filtering by section. Look for
config files in the following order in order to allow easy overloading of default values
(for each directory, a platform subdirectory is also searched)
<ul>
<li>1) Executable directory (C:/path/bin/platform/build/exe)
<li>2) Executable directory "config" subdirectory (C:/path/bin/platform/build/config)
<li>3) Executable directory processed "config" subdirectory (C:/path/config)
      This step is performed by identifying if the path contains
      <ul>
        <li>1) known directories (bin)
        <li>2) a platform identifier (win32,win64,osx,ios,android,raspberrypi)
        <li>3) a build identifier (debug,release,profile,deploy)
      </ul>
      and if so cleaning away these subdirectories. This allows you to have binaries
      sorted on platform/build under a common "bin" directory, while placing configs
      in a unified config directory outside the binary directory.

For desktop builds (Windows, MacOSX, ...), if build is debug/release (i.e not deploy)
<li>4) Initial working directory

For Android development
<li>5) Application asset manager config dir (/config)

For iOS & MacOSX development (non-bsdutil apps)
<li>5) Application bundle config dir (/path/to/exe.app/Contents/Resources/config)

Other platforms:
<li>5)

For desktop platforms (Windows, MacOSX, ...)
<li>6) Current working directory (C:/current/dir)
<li>7) Current working directory "config" subdirectory (C:/current/dir/config)
<li>8) Command line --configdir directive (not in deploy builds)

If built_in flag is false, the following directories are also searched, with
[config_dir] being the application config_dir path set when initializing the library

For Windows development, the user app directory
<li>9) C:/Users/[username]/AppData/Local/.[config_dir]

For Linux development, the user app directory
<li>9) /home/[username]/.[config_dir]

For MacOSX development, the user app directory
<li>9) /Users/[username]/.[config_dir]
</ul>
\param name      File/stream name (will be opened with stream_open)
\param length    Length of stream name
\param section   Optional filter, which will only load the section matching
                 the given filter_section. Set to 0 to load all sections
\param built_in  Flag indicating that only built-in config files should be loaded
\param overwrite If false, only set new values. If true, allow setting values to
                 existing section:key pairs */
FOUNDATION_API void
config_load(const char* name, size_t length, hash_t section, bool built_in, bool overwrite);

/*! Parse config declarations from a stream, optionally filtering on a specific section
\param stream    Stream to read from (will read until EOS encountered)
\param section   Optional filter, which will only load the section matching the
                 given filter_section. Set to 0 to parse all sections
\param overwrite If false, only set new values. If true, allow setting values to
                 existing section:key pairs */
FOUNDATION_API void
config_parse(stream_t* stream, hash_t section, bool overwrite);

/*! Write config declarations to a stream, optionally filtering on a specific section
\param stream    Stream to write to
\param section   Optional filter, which will only write section matching the
                 given filter_section. Set to 0 to write all sections
\param map       Function mapping hash values to strings */
FOUNDATION_API void
config_write(stream_t* stream, hash_t section, string_const_t (*map)(hash_t));

/*! Parse config declarations given on command line
\param cmdline   Command line array
\param num       Number of arguments on command line */
FOUNDATION_API void
config_parse_commandline(const string_const_t* cmdline, size_t num);
