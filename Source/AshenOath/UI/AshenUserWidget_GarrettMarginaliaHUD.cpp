// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_GarrettMarginaliaHUD.h"

void UAshenUserWidget_GarrettMarginaliaHUD::UpdateMarginaliaForTrust(float TrustScore)
{
	if (TrustScore >= 0.70f)
	{
		MarginaliaText = TEXT("Kaelen: The trigger plate is counter-balanced for your swing. We've got this.");
		bShowFriendlyDoodles = true; // Friendly sketches & golden starbursts
	}
	else if (TrustScore <= 0.35f)
	{
		MarginaliaText = TEXT("Make sure the shear pins are snug. Kaelen's heavy boots will set this off if he rushes.");
		bShowFriendlyDoodles = false; // Clinical, cold sketches
	}
	else
	{
		MarginaliaText = TEXT("Standard deployment specs. Double-wrap the sulfur cord.");
		bShowFriendlyDoodles = false;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_GarrettMarginaliaHUD: Marginalia updated for Trust %.2f -> Doodles: %s"),
		TrustScore, bShowFriendlyDoodles ? TEXT("YES") : TEXT("NO"));
}
