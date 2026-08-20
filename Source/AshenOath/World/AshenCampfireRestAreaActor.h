// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenCampfireRestAreaActor.generated.h"

UENUM(BlueprintType)
enum class EAshenCampfireRestState : uint8
{
	Cold,
	Kindled,
	Resonating,
	Extinguished
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCampfireRestStateChanged, EAshenCampfireRestState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCampfireRestTriggered, AActor*, InteractingCharacter, float, ActiveResonancePotential);

/**
 * AAshenCampfireRestAreaActor
 * Interactive world actor representing the Campfire Rest Area.
 * Manages safe-zone rest transitions, pausing aggressive AI threat perception,
 * and preparing the Identity Compilation sequence.
 */
UCLASS()
class ASHENOATH_API AAshenCampfireRestAreaActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenCampfireRestAreaActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Campfire")
	FOnCampfireRestStateChanged OnCampfireStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Campfire")
	FOnCampfireRestTriggered OnCampfireRestTriggered;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Campfire")
	EAshenCampfireRestState CurrentState = EAshenCampfireRestState::Cold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Campfire")
	float RestWarmthRadius = 600.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Campfire")
	void KindleCampfire();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Campfire")
	void TriggerCampfireRest(AActor* InteractingCharacter);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Campfire")
	void ExtinguishCampfire();
};
