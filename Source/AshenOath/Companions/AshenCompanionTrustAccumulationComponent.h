// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionTrustAccumulationComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionTrustChanged, FName, CompanionID, float, NewTrustLevel);

/**
 * UAshenCompanionTrustAccumulationComponent
 * Actor Component processing OnCompanionProtectiveAction (+0.05), OnTacticalAbandonment (-0.10), and OnOathFulfilled (+0.15) deltas into imprints.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionTrustAccumulationComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionTrustAccumulationComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Companions")
	FOnCompanionTrustChanged OnTrustChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companions")
	float GarrettTrust = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companions")
	float SerafinaTrust = 0.5f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void ProcessProtectiveAction(FName CompanionID);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void ProcessTacticalAbandonment(FName CompanionID);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void ProcessOathFulfilled();
};
