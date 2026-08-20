// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenPsychologicalOSViewModelBindingAuditor.generated.h"

UCLASS()
class ASHENOATHEDITOR_API UAshenPsychologicalOSViewModelBindingAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Tooling")
	bool AuditViewModelBindings();

private:
	int32 TotalAuditedBindings = 0;
};
