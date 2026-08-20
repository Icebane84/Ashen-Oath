// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenBatchAuthoringUtilityWidget.h"
#include "AshenBatchAuthoringSubsystem.h"

void UAshenBatchAuthoringUtilityWidget::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenBatchAuthoringUtilityWidget: Editor Utility Widget initialized."));
}

bool UAshenBatchAuthoringUtilityWidget::TriggerBatchCreation(const FAshenTriDomainBatchPayload& Payload)
{
	if (UAshenBatchAuthoringSubsystem* BatchSub = GEditor->GetEditorSubsystem<UAshenBatchAuthoringSubsystem>())
	{
		return BatchSub->OrchestrateNewFeatureBatch(Payload);
	}
	return false;
}
