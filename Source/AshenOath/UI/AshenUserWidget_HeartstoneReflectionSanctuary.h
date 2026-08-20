// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_HeartstoneReflectionSanctuary.generated.h"

/**
 * UAshenUserWidget_HeartstoneReflectionSanctuary
 *
 * UMG backing widget for Heartstone Sanctuary ("Who do I become next?").
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_HeartstoneReflectionSanctuary : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void ReflectAtHeartstoneSanctuary(FName IdentityArchetype, float IntegrationProgressPercent);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName ActiveIdentityArchetypeTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float ActiveIntegrationProgressPercent = 0.0f;
};
