// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenMartyrsPivotChordComponent.h"

UAshenMartyrsPivotChordComponent::UAshenMartyrsPivotChordComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsInterceptHolding = false;
}
void UAshenMartyrsPivotChordComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenMartyrsPivotChordComponent::CheckMartyrsChord(bool bL3Pressed, bool bR3Pressed, bool bR1Pressed, bool bTrianglePressed)
{
	const bool bSticksClicked = (bL3Pressed && bR3Pressed);
	const bool bGripHeld = (bR1Pressed && bTrianglePressed);

	bIsInterceptHolding = (bSticksClicked && bGripHeld);

	if (bIsInterceptHolding)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenMartyrsPivotChordComponent: MARTYR'S PIVOT CHORD HELD (L3+R3 + R1+Triangle)!"));
	}

	return bIsInterceptHolding;
}
