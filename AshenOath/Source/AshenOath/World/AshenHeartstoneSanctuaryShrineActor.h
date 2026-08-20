// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenHeartstoneSanctuaryShrineActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHeartstoneAttunedSignature, FName, ShrineID, float, ResonancePower);

/**
 * AAshenHeartstoneSanctuaryShrineActor
 *
 * Interactive World Actor for Heartstone shrines enabling identity evolution reflections.
 */
UCLASS()
class ASHENOATH_API AAshenHeartstoneSanctuaryShrineActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenHeartstoneSanctuaryShrineActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|HeartstoneShrine")
	void AttuneToHeartstone(float Power = 100.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|HeartstoneShrine|Events")
	FOnHeartstoneAttunedSignature OnHeartstoneAttuned;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|HeartstoneShrine")
	bool bIsAttuned = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|HeartstoneShrine")
	FName ShrineID;
};
