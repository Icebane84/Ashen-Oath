// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 602: Ashen User Widget Heartstone Reflection Sanctuary

#include "AshenUserWidget_HeartstoneReflectionSanctuary.h"

void UAshenUserWidget_HeartstoneReflectionSanctuary::ReflectAtHeartstoneSanctuary(FName IdentityArchetype, float IntegrationProgressPercent)
{
	ActiveIdentityArchetypeTag = IdentityArchetype;
	ActiveIntegrationProgressPercent = FMath::Clamp(IntegrationProgressPercent, 0.0f, 100.0f);

	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_HeartstoneReflectionSanctuary: HEARTSTONE SANCTUARY REFLECTION -> Archetype '%s' | Integration: %.1f%%."),
		*IdentityArchetype.ToString(), ActiveIntegrationProgressPercent);
}
