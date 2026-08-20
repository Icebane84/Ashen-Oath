// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaBurnoutComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBurnoutLevelChanged, float, NewBurnoutLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBurnoutFeverThresholdCrossed);

/**
 * UAshenSerafinaBurnoutComponent
 * Tracks empathic burnout threshold (0.0 to 100.0) inducing physical fatigue & fever states at > 70.0.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaBurnoutComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSerafinaBurnoutComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Burnout")
	FOnBurnoutLevelChanged OnBurnoutLevelChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Burnout")
	FOnBurnoutFeverThresholdCrossed OnBurnoutFeverThresholdCrossed;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Burnout")
	float CurrentBurnout = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Burnout")
	bool bIsBurnedOut = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Burnout")
	float FeverThreshold = 70.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Burnout")
	void AddBurnout(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Burnout")
	void AccumulateEmpathicBurnout(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Burnout")
	void DissipateBurnout(float DeltaTime, float DissipationRate = 2.0f);
};
