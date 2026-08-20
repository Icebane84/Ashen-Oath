// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_TripartiteInterpretationHUD.h"

void UAshenUserWidget_TripartiteInterpretationHUD::RenderInterpretationPackage(const FTripartiteInterpretationPackage& InPackage)
{
	ActivePackage = InPackage;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_TripartiteInterpretationHUD: Rendered Tripartite Interpretation (Kaelen: \"%s\", Garrett: \"%s\", Serafina: \"%s\")."),
		*ActivePackage.KaelenSubjectiveProse, *ActivePackage.GarrettTacticalNote, *ActivePackage.SerafinaGraceLeaf);
}
