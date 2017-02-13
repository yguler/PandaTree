#ifndef PandaTree_Objects_HLTBits_h
#define PandaTree_Objects_HLTBits_h
#include "Constants.h"
#include "../../Framework/interface/Singlet.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class HLTBits : public Singlet {
  public:
    typedef Singlet base_type;

    HLTBits(char const* name = "");
    HLTBits(HLTBits const&);
    ~HLTBits();
    HLTBits& operator=(HLTBits const&);

    void set(unsigned iB) { words[iB / 64] |= (1 << (iB % 64)); }
    bool pass(unsigned iB) const { return ((words[iB / 64] >> (iB % 64)) & 1) != 0; }

    ULong64_t words[16]{};

    /* BEGIN CUSTOM HLTBits.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

  protected:
    void doSetStatus_(TTree&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&) const override;
    utils::BranchList doGetBranchNames_() const override;
    void doSetAddress_(TTree&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
    void doBook_(TTree&, utils::BranchList const& = {"*"}) override;
    void doReleaseTree_(TTree&) override;
    void doInit_() override;
  };

  /* BEGIN CUSTOM HLTBits.h.global */
  /* END CUSTOM */

}

#endif
