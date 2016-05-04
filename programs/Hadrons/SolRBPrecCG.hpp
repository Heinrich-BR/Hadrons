/*******************************************************************************
Grid physics library, www.github.com/paboyle/Grid 

Source file: programs/Hadrons/SolRBPrecCG.hpp

Copyright (C) 2016

Author: Antonin Portelli <antonin.portelli@me.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

See the full license in the file "LICENSE" in the top level distribution 
directory.
*******************************************************************************/

#ifndef Hadrons_SolRBPrecCG_hpp_
#define Hadrons_SolRBPrecCG_hpp_

#include <Hadrons/Global.hpp>
#include <Hadrons/Module.hpp>
#include <Hadrons/ModuleFactory.hpp>

BEGIN_HADRONS_NAMESPACE

/******************************************************************************
 *                     Schur red-black preconditioned CG                      *
 ******************************************************************************/
class SolRBPrecCG: public Module
{
public:
    class Par: Serializable
    {
    public:
        GRID_SERIALIZABLE_CLASS_MEMBERS(Par, std::string, action,
                                             double     , residual);
    };
public:
    // constructor
    SolRBPrecCG(const std::string name);
    // destructor
    virtual ~SolRBPrecCG(void) = default;
    // parse parameters
    virtual void parseParameters(XmlReader &reader, const std::string name);
    // dependencies/products
    virtual std::vector<std::string> getInput(void);
    virtual std::vector<std::string> getOutput(void);
    // execution
    virtual void execute(Environment &env);
private:
    Par par_;
};

MODULE_REGISTER(SolRBPrecCG);

END_HADRONS_NAMESPACE

#endif // Hadrons_SolRBPrecCG_hpp_