// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenIntegrationRitualComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIntegrationRitualCompleted, float, DebtCleared);

/**
 * UAshenIntegrationRitualComponent
 * Tactile ritual component for burning traumatic soul remnants and restoring psychological clarity.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenIntegrationRitualComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenIntegrationRitualComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Ritual")
	FOnIntegrationRitualCompleted OnIntegrationRitualCompleted;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Ritual")
	bool PerformSoulIntegrationRitual(float TraumaDebtToClear);
};
