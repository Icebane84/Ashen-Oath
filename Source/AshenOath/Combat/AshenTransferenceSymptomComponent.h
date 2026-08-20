// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTransferenceSymptomComponent.generated.h"

/**
 * UAshenTransferenceSymptomComponent
 * Tracks somatic physical symptoms of absorbed Nyxian rot in Serafina (muffled black sap coughs, trembling hand physics when Burnout >= 0.50).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTransferenceSymptomComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTransferenceSymptomComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	float HandTremorIntensity = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	bool bIsCoughingBlackSap = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic")
	void UpdateTransferenceSymptoms(float BurnoutScalar);
};
