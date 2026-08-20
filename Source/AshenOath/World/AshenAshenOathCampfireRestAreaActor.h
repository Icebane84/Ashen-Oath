// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenAshenOathCampfireRestAreaActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCampfireRestTriggeredSignature, FVector, CampfireLocation, bool, bPartyRestRestored);

/**
 * AAshenAshenOathCampfireRestAreaActor
 *
 * Interactive campfire rest area triggering party conversation cutscenes and rest mechanics (Where Light Fades Act 01).
 */
UCLASS()
class ASHENOATH_API AAshenAshenOathCampfireRestAreaActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenAshenOathCampfireRestAreaActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Campfire")
	void TriggerCampfireRest();

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Campfire|Events")
	FOnCampfireRestTriggeredSignature OnCampfireRestTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Campfire")
	bool bIsCampfireLit = true;
};
