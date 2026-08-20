// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Combat/AshenEmpathicNovaTypes.h"
#include "AshenEmpathicNovaSubsystem.generated.h"

/**
 * UAshenEmpathicNovaSubsystem
 * GameInstance Subsystem managing the Empathic Conduit Nova finisher lifecycle, mutual trust gating (>= 0.70), and subsystem invalidation resets.
 */
UCLASS()
class ASHENOATH_API UAshenEmpathicNovaSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Nova")
	ENovaFinisherState CurrentFinisherState = ENovaFinisherState::Inactive;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Nova")
	FEmpathicNovaMetrics CurrentMetrics;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nova")
	bool CanInitiateNova(float MutualTrust, float SerafinaBurnout) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nova")
	bool TriggerNovaExecution();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nova")
	void InvalidateAndResetSubsystems();
};
