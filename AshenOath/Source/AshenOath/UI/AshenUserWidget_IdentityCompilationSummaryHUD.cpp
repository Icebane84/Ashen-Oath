// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_IdentityCompilationSummaryHUD.h"

void UAshenUserWidget_IdentityCompilationSummaryHUD::DisplayCompilationSummary(const FSoulStateVector& InVector, bool bVisible)
{
	DisplayedStateVector = InVector;
	bIsSummaryVisible = bVisible;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_IdentityCompilationSummaryHUD: Identity Summary %s (Resolve: %.2f, GTrust: %.2f, STrust: %.2f)"),
		bIsSummaryVisible ? TEXT("SHOWN") : TEXT("HIDDEN"), DisplayedStateVector.Resolve, DisplayedStateVector.GarrettTrust, DisplayedStateVector.SerafinaTrust);
}
