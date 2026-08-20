// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMasterOrchestrationHub.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMasterHubStatusChangedSignature, bool, bIsHealthy, int32, ActiveSubsystemCount);

/**
 * UAshenMasterOrchestrationHub
 *
 * Master C++ GameInstanceSubsystem binding GameInstance, PAA Orchestrator, Diagnostic HUD,
 * Save Manager, Audio Subsystem, and Soul Constellation Kernel into a production-ready package.
 */
UCLASS()
class ASHENOATH_API UAshenMasterOrchestrationHub : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Hub")
	bool ExecuteMasterDiagnostics();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Hub")
	void EndPlaytestSession();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Hub")
	bool bMasterHubHealthy = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Hub")
	int32 ActiveSubsystemCount = 12;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Hub|Events")
	FOnMasterHubStatusChangedSignature OnHubStatusChanged;
};
