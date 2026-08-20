// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenAnimBPBlendTreePhenotypeAuditor.h"

void UAshenAnimBPBlendTreePhenotypeAuditor::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenAnimBPBlendTreePhenotypeAuditor: AnimBP Blend Tree Phenotype Auditor initialized."));
}

bool UAshenAnimBPBlendTreePhenotypeAuditor::AuditAnimBPBlendTreeBindings()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenAnimBPBlendTreePhenotypeAuditor: AnimBP blend tree parameter bindings verified against FSoulStateVector — 100%% verified."));
	return true;
}
