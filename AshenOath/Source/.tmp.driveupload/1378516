// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "Materials/MaterialParameterCollection.h"
#include "AshenBlackboardInspectorSubsystem.generated.h"

/**
 * UAshenBlackboardInspectorSubsystem
 * Automates the binding of psychological runtime variables to Unreal Engine MPCs and MetaSound graphs.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenBlackboardInspectorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Binds a psychological float to a Material Parameter Collection for visual morphs */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling|Blackboard")
	bool BindVariableToMaterialCollection(FName VariableName, float CurrentValue);

	/** Transmits state data to global MetaSound parameters */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling|Blackboard")
	bool TransmitStateToAudioSubsystem(FName ParameterName, float NormalizedValue);

private:
	UPROPERTY(Transient)
	TObjectPtr<UMaterialParameterCollection> GlobalAshenMPC;
};
