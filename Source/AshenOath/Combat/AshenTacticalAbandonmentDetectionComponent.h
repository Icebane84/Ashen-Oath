// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTacticalAbandonmentDetectionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTacticalAbandonmentDetected, FName, CompanionID);

/**
 * UAshenTacticalAbandonmentDetectionComponent
 * Combat component detecting when Kaelen leaves a companion surrounded by enemies (> 1000uu separation), issuing abandonment imprints.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalAbandonmentDetectionComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTacticalAbandonmentDetectionComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Combat")
	FOnTacticalAbandonmentDetected OnAbandonmentDetected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float AbandonmentDistanceThreshold = 1000.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool CheckTacticalAbandonmentCondition(FName CompanionID, FVector CompanionLocation, FVector PlayerLocation, int32 SurroundingEnemyCount);
};
