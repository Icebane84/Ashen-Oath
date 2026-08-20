// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenCompanionBarkComponent.h"
#include "AshenCompanionBarkTriggerVolume.generated.h"

class UBoxComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBarkVolumeTriggeredSignature, ECompanionType, Companion, FString, Line);

/**
 * AAshenCompanionBarkTriggerVolume
 *
 * Spatial world trigger volume for contextual companion voice barks.
 * Fires a targeted voice bark line on Garrett or Serafina when player enters volume.
 */
UCLASS()
class ASHENOATH_API AAshenCompanionBarkTriggerVolume : public AActor
{
	GENERATED_BODY()

public:
	AAshenCompanionBarkTriggerVolume();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Bark")
	TObjectPtr<UBoxComponent> BoxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Bark")
	ECompanionType TargetCompanion = ECompanionType::Garrett;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Bark")
	FString BarkLine = TEXT("Watch your step, Kaelen!");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Bark")
	bool bPlayOnce = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Bark")
	bool bAlreadyTriggered = false;

	UFUNCTION()
	void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Bark|Events")
	FOnBarkVolumeTriggeredSignature OnBarkVolumeTriggered;
};
